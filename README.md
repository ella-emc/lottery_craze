# lottery_craze
This repository contains an implementation in C and Python of a lottery machine. The program reads entries from a file and writes the winning entries to a separate file.

There are two C source files in this repository. The first one is the initial version instructed to us in our Programming I class. It doesn't use arrays to read the integers in the input file. 

Originally, the C source file reads a .in file and not a CSV file. However, to accommodate to both the C and Python implementations of this program, I decided to tweak the original C source file to be capable of reading and writing CSV values. The principles and algorithm used in the C implementation are fundamentally similar to the ones used in the Python implementation. 

The dataset used as input to the program was sourced from Sohier Dane on Kaggle. This <a href="https://www.kaggle.com/datasets/sohier/ny-state-lotto-winning-numbers/data">link</a> leads to the Kaggle dataset. All the numbers in the dataset are winning lottery numbers in the state of New York since 2001.

<strong>Some remarks on the C implementation: </strong>
<ul>
  <li>Upon execution, the user is asked for a lottery six-number combination.</li>
  <li>The program checks if each number is within the range of 1 to 59. If false, program terminates.</li>
  <li>If the input is valid, the program will now read through the lines in the dataset, looking for six-number, five-number, four-number, and three-number matches.</li>
  <li>Each number of matched combination in the dataset is written in another CSV file containing the information from the dataset. In other words, when there are three matched numbers between the input and the data from the file, the number from the dataset will be written in another file containing three-number winning combinations. And so on.</li>
  <li>This program assumes that each number is unique. (There is no repeating number in each line.)</li>
</ul>


<strong>Remark on the Python implementation: </strong>
<ul>
  <li>Only the combinations with winners will have a file written specifically for it, unlike in the C implementation where every number of combination yielded a file.</li>
</ul>
