local M = {}

local function read_file(file_path)
    local file = io.open(file_path, "r")
    if not file then return nil end

    local content = {}
    local start_reading = false

    for line in file:lines() do
        if start_reading then
            table.insert(content, line)
        elseif line:find("/// begin") then
            start_reading = true
        end
    end

    file:close()
    return table.concat(content, "\n")
end

local function load_snippets()
    local snippets = {}
    local base_dir = vim.g["cpa#dir"] or '~/cpa-cache/cache/'
    base_dir = vim.fn.expand(base_dir)

    local scan_dir
    scan_dir = function(dir)
        local entries = vim.fn.readdir(dir)
        for _, entry in ipairs(entries) do
            local full_path = dir .. '/' .. entry
            if vim.fn.isdirectory(full_path) == 0 then
                if entry:match("%.hpp$") then
                    local keyword = entry:gsub("%.hpp$", "")
                    snippets[keyword] = read_file(full_path)
                end
            else
                scan_dir(full_path)
            end
        end
    end

    scan_dir(base_dir)
    return snippets
end

local snippets = load_snippets()

local function cpa_command(args)
    local keyword = args.args
    local snippet = snippets[keyword]
    if snippet then
        vim.fn.setreg('"', snippet)
        print("Snippet for '" .. keyword .. "' copied to register.")
    else
        print("Snippet not found for: " .. keyword)
    end
end

vim.api.nvim_create_user_command('Cpa', cpa_command, { nargs = 1 })

M.load_snippets = load_snippets
return M

