# My own versions of some popular Linux programs. 
All programs are written in C.

<h1>Function Usage:</h1>

<h2>./new_cat [file_name.txt]</h2> <br/>
Print the content of [file_name.txt] <br/>
If there is no second argument, repeat what the user types on stdin back to stdout <br/>
(until the user hits CTRL+D to indicate EOF). <br/>

<h2>./new_echo [arg] [arg] ... [arg]</h2> <br/>
Print all [arg] arguments to stdout. <br/>
If there are no [arg] arguments, simply print a newline and end the program. <br/>

<h2>./new_tail [-n N] [file_name.txt]</h2> <br/>
If [file.txt] is specified, print the last N lines of that file (default is 5 lines if -n is not used). 
Otherwise, read from stdin until the user hits CTRL+D. <br/>
The [file.txt] and [-n N] order should not matter – both orderings are allowed. <br/>

<h2>./new_wc [-l|c] [file.txt]</h2> <br/>
If [file.txt] is specified, print a count of the number of words in file.txt. <br/>
If the -l (lowercase L) flag is specified, print the number of lines and the number of words. <br/>
If the -c flag is specified, print the number of characters and the number of words. <br/>
The [file.txt] and [-l|c] flag order does not matter. <br/>
