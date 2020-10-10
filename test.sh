#!/bin/bash
#Author Duarte Dias
<<COMMENT
The purpose of this program is to automatically analize all files and files in a test directory and give user feedback about the number of errors.
If you use the same name for the log file changes will be overwriten
This script takes 2 parameters, test directory and logfile name.
COMMENT
if [ "$#" -ne 2 ]; then
    echo "There should be 2 parameters in this script, test directory and logfile name"
    exit 9
fi
echo "Error Reported Analysis" > $2.info
ls -a | grep  ".txt" | while read -r line ; do
		echo "Processing $line"
		processed=`sed 's/.txt/.out/' <<<$line`	
		found=`find $1 -name $processed`
		if [ "$found" ];
		then
			result=`diff $line 2.txt`
			echo "$result"
			if [ "$result" ]; 
			then
				echo "Error found "
				echo "On file $line" >> $2.info
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
