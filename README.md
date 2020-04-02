# COASt Documentation
### To be populated once the project is done :grin:

## TAGS
Tags define the the basics and the entirety of the program's usefulness. There are many useful tags that you may use at will to create a script of your choosing. Almost every tag is used in its own line, except for the "<!Escape>" tag.  
The specific uses and the limitations of each tag is explained in detail later in this document.
## Script Files
The script files are where you write the story that you want. Every pertinent file must have a ".st" extension in order for the program to be able to parse it.

### List of Tags

- [<!Story>](#story-tag-story)
- [<!Wait>](#wait-tag-wait)
- [<!Escape>](#escape-tag-escape)
- [<!Prompt>](#prompt-tag-prompt)
    - [<!Prompt_Info>](#prompting-information-tag-prompt_info)
    - [<!Prompt_Choice>](#prompting-a-choice-tag-prompt_choice)
- [<!CheckPoint>](#checkpoint-tag-checkpoint)

# Tag Explanations
## Story Tag "<!Story>"


The story tag will be the most commonly used tag in any script files. Place a "<!Story>" tag on a line of its own, followed by lines of text. The text will be printed as is, and escape characters are printed as they are; for instance, typing "\n" will print "\n" and not a new line.  
You may also print variables using the Escape tag inline. More on this in the "Escape Tag" section.  

Code Sample

```
<!Story>
    Lorem Ipsum something something something.
Story tag will print this as is... with tabs and all.
```

## Wait Tag "<!Wait>"
The idea of the Wait tag is to put a stop in between long blocks of Story texts. this will stop printing the lines and wait for player to press enter before continuing...  
This is also the time when the player can quit the program safely. It can only be in the "story" sections and is in a line by it self.

Code Sample
```
<!Story> 
    Lorem Ipsum something something something.
Story tag will print this as is... with tabs and all.
<!Wait>
    And then the program waits for the player to press enter before it prints this line.
```

## Escape Tag "<!Escape>"
The Escape tags allows you to use variables in your scripts. This is, as of now, the only tag that may be and has to be used inline. This tag will always preceed the name of a variable and the variable will be replaced by what ever the value of the variable is stored by the program.  
The program stops when you try to escape a variable that doesn't exist. There is a "compiler" in works that will check this and inform the user before running the program itself, but until then the script-writer is responsible for keeping track of all the variables and their potential values.

Code Sample
```
<!Story> 
    Lorem Imps. I have <!Escape> obj_name in my pocket...
```
In the example, "obj_name" will be replaced whatever the value is for the variable in the program.
## Prompt Tag "<!Prompt>"
This tag is always accompanied by a more specific prompt tag. It gets its own line and the secondary tag is also in a line of its own, directly following this tag. On its own, this tag does nothing.

FOR SAMPLE, Look at the secondary prompt tags directly below.
## Prompting Information Tag "<!Prompt_Info>"
This tag is used for getting user input and saving them to variables to be used later on. This tag is always in a line of its own and is preceeded by the general "Prompt" tag.
Code Sample
```
<!Prompt>
<!Prompt_Info>
What is your name?
user_name
```
The prompt info is followed by a Question... this is optional and may be left blank if the script-writer deems it unnecessary. Then whatever the user inputs will be recorded in the program and will be referencable using the user_name variable and the escape command. 

Note that the question line in the sample may also use the Escape tag inside it to print the variable instead of plain text... i.e.
```
What is your <!Escape> var_name ?
```
The highlighted line will print as: What is your (var_value)?
## Prompting a Choice Tag "<!Prompt_Choice>"
This tag is the essence of this program. It allows you(script-writer) to make branches in your script and allows the player to "Choose their own adventure."
This tag, just like the other specific prompt-tags, directly follows the <!Prompt> tag and gets a line of its own. 

Code Sample
```
<!Prompt>
<!Prompt_Choice>
N
1) You go with choice 1.
choice_1_file_name
.
.
N) You go with choice N.
choice_N_file_name
```
The N in the sample code stands for the number of choices given to the player.

The number should be followed by N pairs of lines... The first of the pair will be a choice that will be displayed to the player as written (Escape tags may be used in these lines as well).

The second line will be the name of a script-file corresponding to the paired choice...
Whichever choice the user decides, that file will be opened and the current file will be closed...
as such, anything after a Prompt_Choice tag ends is never red by the program...

## Checkpoint Tag "<!CheckPoint>"
Check points create a save for the player to come back to should they close the program. For now, Checkpoints can only be set at the begining of a file. To use this functionality, just put the check point tag "<!CheckPoint>" at the start of any file.