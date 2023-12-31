import os
from pathlib import Path
import pypandoc

def bl_directory(directory):
    topic_name = os.path.basename(directory)
    cur_md = ''
    cur_code = ''
    
    for file in directory.iterdir():
        try:
            if not file.is_dir():
                if file.suffix == '.md':
                    with open(file, 'r') as file:
                        cur_md = file.read()
                        
                        if cur_md.split('\n')[0].strip().startswith('#'):
                            topic_name = cur_md.split('\n')[0].strip()[1:].strip()
                            cur_md = '\n'.join(cur_md.splitlines()[1:])
                        
                elif file.suffix == '.hpp':
                    with open(file, 'r') as file:
                        raw_code = file.read()
                        
                        begin_found = False

                        for line in raw_code.split('\n'):
                            if begin_found:
                                cur_code += line + '\n'
                            else:
                                if '/// begin' in line.strip():
                                    begin_found = True

        except:
            pass

    return (topic_name, cur_md, cur_code)


def ml_directory(directory):
    cur_topics = []

    for folder in directory.iterdir():
        if folder.is_dir():
            this_topic = bl_directory(folder)
            cur_topics.append(this_topic)

    return cur_topics

def tl_directory(directory):
    for folder in directory.iterdir():
        if folder.is_dir() and (not 'obsidian' in os.path.basename(folder)):
            topics = ml_directory(folder)
            dir_roots.append((os.path.basename(folder), topics))

def to_md(folders):
    md_file = 'CPA Cache Reference Sheet'
    md_file += '  \n' + ('=' * len(md_file)) + '  \n  \n**Table of Contents**  \n'

    try:
        with open(root_directory / Path('heading.md'), 'r') as file:
            md_file = file.read()
    except:
        pass

    toc = ''
    content = ''

    folders.sort()

    for i in range(len(folders)):
        folder = folders[i]
        toc += f'- [{i + 1}. {folder[0]}](#{i+1}-{folder[0]})  \n'
        content += f'## {i + 1}. {folder[0]}  \n'
        folder[1].sort()

        for j in range(len(folder[1])):
            topic = folder[1][j]
            toc += f'\t- [{i + 1}.{j + 1} {topic[0]}](#{i + 1}{j + 1}-{topic[0].lower().strip().replace(" ", "-")})  \n'
            content += f'#### {i + 1}.{j + 1} {topic[0]}  \n'
            content += f'{topic[1]}  \n  \n'
            content += f'```cpp\n{topic[2]}```  \n'
    
    return md_file + '\n  \n' + toc + '\n  \n' + content

def create_mkfile(content):
    with open(Path(input_md_file), 'w') as mk_file:
        mk_file.write(content)

# Convert to markdown
root_directory = Path('./cache/')
input_md_file = 'reference_sheet.md'
output_pdf_file = 'reference_sheet.pdf'

dir_roots = []
tl_directory(root_directory)

create_mkfile(to_md(dir_roots))

output = pypandoc.convert_file(input_md_file, 'pdf', outputfile=output_pdf_file, 
                               extra_args=['-V', 'geometry:margin=1in', '--wrap=preserve'])

print('See reference_sheet.pdf')
