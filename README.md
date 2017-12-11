# CodeBarn

A source code repository for items discussed on my technical blog at codebarn.tech.

## UVa Online Judge

To get started, go to https://uva.onlinejudge.org/, create an account, and start problem solving!  I will post solutions to problems from this site in the $/uva folder.  Each problem will consist of a single C++ source file, named according to the UVa Online Judge problem ID.

### Getting Started

Download the C++ source file for the target problem, compile with the following (where <main> can be replaced with the filename of a given problem):

$ g++ -std=c++11 -o main main.cc

Either download the sample input from UVa Online Judge (https://uva.onlinejudge.org/) or copy it from the problem description and save to file (e.g. sample-input.txt).  Run your compiled program (e.g. main) with input piped through standard input:

$ ./main < ./sample-input.txt

Optionally, pipe program output to a file and diff against the expected sample output from the problem description:

$ ./main < ./sample-input.txt > ./my-output.txt && diff ./my-output.txt ./sample-output.txt

## Author

Cody Barnson

## Acknowledgments

Thank you to Dr. Howard Cheng for all the help and guidance provided over the years. 