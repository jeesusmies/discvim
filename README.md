# discvim (Discord Vim)
Discord Rich Presence (rpc) for Vim, written in C.
NOTE: I've intended to make this work only in Linux.

**Can't add assets to discord applications, so the rpc is without pictures right now.**

## Installing
This should work with any plugin manager, but I've tested it only on [Pathogen](https://github.com/tpope/vim-pathogen)
```
cd .vim/bundle/ && git clone https://github.com/jeesusmies/discvim.git && cd discvim
mv discvim.vim ../autoload
```

## Usage
To start the rpc, run `:StartDiscvim`.
After usage, run `:StopDiscvim`.

**auto start doesn't work rn**
