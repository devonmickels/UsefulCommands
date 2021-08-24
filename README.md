# UsefulCommands

### Git Commands

Remove all cached files in .gitignore. This will clear all files in your repository that are supposed to have been ignored. [1](https://stackoverflow.com/questions/13541615/how-to-remove-files-that-are-listed-in-the-gitignore-but-still-on-the-repositor)
```
git rm --cached `git ls-files -i -c --exclude-from=.gitignore`
```

On Git Bash:
```
git ls-files -i -c --exclude-from=.gitignore | xargs git rm --cached  
```
