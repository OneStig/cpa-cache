local function read_file(file_path)
    local file = io.open(file_path, "r")
    if not file then return nil end
    local content = file:read("*all")
    file:close()
    return content
end

local function find_file_by_keyword(keyword)
    -- Base directory for cache
    local base_dir = vim.fn.stdpath('config') .. '/cache/'

    -- List of all subdirectories in the cache
    local topics = {"graphs", "range"}  -- Add more topics as needed

    for _, topic in ipairs(topics) do
        local topic_dir = base_dir .. topic .. '/'

        -- Iterate through each topic's subdirectories
        for file in io.popen('ls "'..topic_dir..'"'):lines() do
            local md_file = topic_dir .. file .. '/' .. file .. '.md'
            local md_content = read_file(md_file)

            if md_content then
                -- Check if the keyword exists in the markdown file
                for line in md_content:gmatch("[^\r\n]+") do
                    if line:find("#### keywords") then
                        for kw in line:gmatch("%S+") do
                            if kw == keyword then
                                return topic_dir .. file .. '/' .. file .. '.h'
                            end
                        end
                    end
                end
            end
        end
    end

    return nil
end

local function cpa_command(keyword)
    local file_path = find_file_by_keyword(keyword)
    if not file_path then
        print("Keyword not found: " .. keyword)
        return
    end

    local content = read_file(file_path)
    if not content then
        print("Failed to read file: " .. file_path)
        return
    end

    -- Set content to unnamed register
    vim.fn.setreg('"', content)
end

-- Register the command
vim.api.nvim_create_user_command('Cpa', function(input)
    cpa_command(input.args)
end, { nargs = 1 })

