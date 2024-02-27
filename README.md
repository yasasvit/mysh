Names: Pratyoy Biswas, Yasasvi Tallapaneni\

# Test Plan:
## Two Extensions:
**(Tests explained more in correctness testing)**
1. Home Directory 
- When `cd` is called with no arguments or `cd ~ ` is called, it changes the current directory to the home directory.
- Tokens beginning with `~` are replaced as relative, it is interpreted as relative to the home directory
2. Directory Wildcards
- We allow for one wildcard in directory names.
- If more than one wildcard is in directory, we simply state that "no such file or directory exists". 
- Matches the wildcard directory, traverses the directory to match the rest of the path (if needed)
- If multiple matches exist for `ls`, it prints out all the matches. If multiple matches exist for `cd`, it goes to the directory that first matches.
## Correctness Testing: 
To check that our shell runs as intended, we utilized the commands used in the file `script` to test in both batch mode (by running `./mysh script`) and in interactive mode (by running `./mysh` and then typing the commands in `script` in the terminal):
1. First, we test `pwd` to check if we are in our current working directory and do so in subsequent times to check if the appropriate commands worked.\
**Note: We tested the home directory commands in our own terminal because it depends on the user's directory structure. It is not included in ``script``.**
2. Then, we type `cd` to check move into the home directory. (Ext. 1)
3. We `echo this is the home directory` to test the command `echo`. Each subsequent echo serves the same purpose. 
4. Then, we test our normal `cd` command via `cd CS214/shell` to go back into our old working directory and `pwd` to check if it worked.
5. Then, we tested `cd ~/CS211` to see if our new directory we entered was relative to the home directory. (Ext 1.)
6. We tested `cd ..` to see if we could go back to the parent directory. (Ext. 1)
7. Then, we checked the case where we `cd does_not_exist` to see if the appropriate ! and error message is printed.
8. We then tested the bare name commands such as `ls`, `cat`, `sort`, and `wc` to test if the proper output was printed after the command. 
9. We also performed some error checks such as `cat file_not_exist` and `doesnotexistcmd` which output the appropriate error message and precede the next `mysh>` with a !. 
10. We tested if another C file can run on mysh by compiling `gcc -g -std=c99 -Wall -fsanitize=address,undefined -o testc testc.c` and running `./testc`.
11. Then we tested the wildcards for files by checking if `ls *.c`, `ls *.txt`, and `ls w*` gave the correct output.
12. We then tested the directory wildcards by placing the wildcards at different places and running these commands: `ls */test1`,
`cd testing/y*/nested`, and `ls test_files/*ng`, which all functioned correctly. (Ext. 2)
13. Then, we tested some miscellaneous commands such as `rm -rf baz` and `mkdir -p baz`. 
14. We also tested if we parsed the redirection symbols appropriately if spaces were missing via `echo foo bar quux>baz1`, `echo foo bar> baz2 quux`, `echo foo >baz3 bar quux`, and `echo > baz4 foo bar quux`, and they all functioned properly. 
15. We further tested if the output and input redirection worked by testing more commands such as `echo new text > baz4`, `wc -w < baz4`, and also error checked by running `wc < file_not_exist`. 
16. We tested if piping functioned properly and tokenizes (regardless of the existence of spaces) by running `ls -t |sort -r`.
17. We also tested if piping, input redirection, and output redirection could work in conjunction by testing if thses commands `ls -t |sort >test_files/test4` and `cat < test5|cat > test6` functioned properly, which they did.
18. Finally, we tested if the `exit` command worked properly with pipes and did not print any commands that were placed in the following lines by running `exit  | cat < `.

Running `./mysh script` (batch mode) in terminal gives the following output:
```
/common/home/yt397/shell/shell
this is the parent directory
/common/home/yt397/shell
/common/home/yt397/shell/shell
this directory does not exist
cd: No such file or directory
/common/home/yt397/shell/shell

baz  Makefile  mysh  mysh.c  other_dir  README.md  script  test_files  testing  words.c  words.h
hello world
this is test file #1
are
these
unsorted
words
69 test_files/test3
cat: file_not_exist: No such file or directory
doesnotexistcmd: command not found

we can run another C file from mysh
Running C program.
done

wildcards
mysh.c  words.c
ls: cannot access '*.txt': No such file or directory
words.c  words.h
directory wildcards (Ext. 3)
other_dir/test1  test_files/test1
ls: cannot access 'test_files/*ng': No such file or directory

original word count:
3
new word count:
2
this file does not exist
open: No such file or directory

files sorted in time order
baz  test_files  script  README.md  mysh  mysh.c  other_dir  Makefile  testing  words.c  words.h
pipe to sort in reverse order
words.h
words.c
testing
test_files
script
README.md
other_dir
mysh.c
mysh
Makefile
baz
redirect output to test4
/common/home/yt397/shell/shell
printing redirected output

combination of input and output redirection with pipes
baz
Makefile
mysh
mysh.c
other_dir
README.md
script
test_files
testing
words.c
words.h
final test
/common/home/yt397/shell/shell
```

All output was printed exactly as intended, in both batch mode and interactive mode.