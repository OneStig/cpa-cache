# cpa-cache
cpa-cache (Competitive Programming Algorithms Cache) is an open source database of useful code for various contests that can be compiled into a reference sheet, or installed as a neovim plugin to yank snippets into the unnamed register. Currently only has implementations for C++.

## Usage
- To compile everything into a reference sheet, run `pdfify.py`
    - Requires [Pandoc](https://pandoc.org/installing.html)
- neovim
    - Install this plugin [`OneStig/cpa-cache`](https://github.com/OneStig/cpa-cache) with your favorite plugin manager
    - Set `g:cpa#dir` to the cache directory of this repo

## Organization
- `/cache` - Database of useful datastructures, algorithms, and code snippets
    - Subdirectories will organize by topics, and each entry will contain both a code snippet and a corresponding markdown file with my explanations and thoughts.
    - Each markdown file starts with a level 1 heading with the name of the topic, followed by a level 4 heading with the text `keywords`, after which follows a comma separated list of keywords that can be used to yank the associated snippet into neovim.

## Contribution
- Feel free to open a pull request and add to this collection
