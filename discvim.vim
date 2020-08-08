let s:rpc_file_edit = '/tmp/discvim_editing.txt'
let s:rpc_file_file = '/tmp/discvim_file.txt'
let s:file_dir = expand('/home/ilari/.vim/bundle/discvim') "change this with your discvim path

func discvim#WriteTmp(timer)
    call writefile(['Editing '], s:rpc_file_edit)
    call writefile(['' . expand('%:t')], s:rpc_file_file)
endfunc

func discvim#StartDiscvim()
    call system('cd ' . s:file_dir . ' ; ./discvim.sh')
    let s:dvtimer = timer_start(5000, 'discvim#WriteTmp', {'repeat': -1})
endfunc

func discvim#StopDiscvim()
    call system('rm -f ' . s:rpc_file_edit)
    call system('rm -f ' . s:rpc_file_file)
    call timer_stop(s:dvtimer)
endfunc
