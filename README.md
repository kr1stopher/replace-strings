# CPSC535-SP21-Project1
Rewriting greeting cards
Author: Kris Swartzbaugh, Campus Email kswartzb@csu.fullerton.edu

# Project Description

Design and build an algorithm related to strings. This algorithm will help reuse texts for greeting cards, by modifying the original string according to a set of input pairs. Example:

S[] = “My dear Anna, let me congratulate you on the beautiful car that you purchased today. It looks very posh. I hope you got a good deal. Cars are expensive but much needed. Best regards, Naomi.”

LS[] = { {“Anna”, “Jovi and Victor”} , { “car”, “house”}, {“today”, “last week”}, {“posh”, “well
built”}}

Output:
R[] = “My dear Jovi and Victor, let me congratulate you on the beautiful house that you purchased last week. It looks very well built. I hope you got a good deal. Cars are expensive but much needed. Best regards, Naomi.”

# Contents 
README - This File 
adv-alg-replace-strings.cpp  - File Containing all code and the algorithm 
replaceStringsInput.txt      - Input text file to be read by the algorithm containing input strings and replacement pairs 
Report.docx                  - Report containing summary of documentation, psuedocode, output screenshot

# Environment 
Built in C++ on linux computer 

# About the Code

The algorithm scans the input text file looking for the appropriate strings and lists of replacements pairs, parsing the replacement pairs appropriately into a vector to be used. Once the appropriate substrings have been replaced, the program prints all updated strings to the screen. The input text is to have the following format:

My dear Anna, let me congratulate you on the beautiful car that you purchased today. It looks very posh. I hope you got a good deal. Cars are expensive but much needed. Best regards, Naomi.
{{"Anna", "Jovi and Victor"} , { "car", "house"}, {"today", "last week"}, {"posh", "well built"}, {"Cars", "Houses"}};

The first line being the string to be modified, without quotation marks, the following line to be the set of replacement pairs. Folliwing lines can have the same format alternating between string to be modified and replacement pairs as the algorithm can take multiple inputs at the same time. 

