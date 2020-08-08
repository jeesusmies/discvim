command! StartDiscvim :call discvim#StartDiscvim()
command! StopDiscvim :call discvim#StopDiscvim()

if exists("g:discvim_autostart")
    if g:discvim_autostart == 1
        StartDiscvim
    endif
endif
