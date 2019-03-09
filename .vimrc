set number
set mouse=a
syntax on
set linebreak
set tabstop=4
set cindent
set iminsert=0
set showmatch
set nowrap
augroup resCur
	autocmd!
	autocmd BufReadPost * call setpos(".", getpos("'\""))
augroup END
