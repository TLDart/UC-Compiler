#!/bin/bash
#Author Duarte Dias
<<COMMENT
The purpose of this program is to automatically analize all files and files in a test directory and give user feedback about the number of errors.
If you use the same name for the log file changes will be overwriten
This script takes 3 parameters, the name of your lex (.l) logfile name and test directory.
COMMENT
if [ "$#" -ne 3 ]; then
    echo "There should be 3 parameters in this script, test directory and logfile name"
    exit 9
fi
echo "Error Reported Analysis" > $2.info
echo "Error Reported Analysis"
# echo $3
ls -a "$3"| grep  "\.c\|.uc" | while read -r line ; do
		echo "Processing $line"
		processed=`sed -E 's/\.c|\.uc/.out/' <<<$line`	
		found=`find $3 -name $processed`
		if [ "$found" ];
		then
			lex $1 
			yacc -d -v uccompiler.y 
			gcc lex.yy.c y.tab.c functions.c print_lib.c -o uccompiler && 
			rm lex.yy.c y.tab.h y.tab.c 
			result=`./uccompiler -t < $3/$line | diff $3/$processed -`
			 #result=`./uccompiler -l < $3/$line | diff $3/$processed -`
			if [ "$result" ]; 
			then
				echo "Error found "
				echo "On file $line" >> $2.info
				echo "$result"
				echo "$result" >> $2.info
			else
				echo "No errors found"
			fi	
		else
			echo "Missing $processed for file $line"
			exit 9
			fi
done
found=`find $2.info`
if [ "$found" ];
then
	errors=`grep "On file" $2.info | wc -l`
	echo "In this run you had $errors files with errors" 
else 
	echo "No errors found in this run"
fi	
