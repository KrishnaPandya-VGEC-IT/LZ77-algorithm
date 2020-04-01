# LZ77-algorithm
LZ77-data compression algorithm 

 Problems with this code:
	 
	1)If at the end, string matches with remaining characters for example, remaining
	  characters are : "ca" and "ca" is present then what to write for <..,..,????>
	  is not given in the algorithm. Hence, algorithm is only applicable where last
	  characters are different. Otherwise it will cause std::out_of_range() exception.
	  We can put '-' in last <????> filled. But as there is no such situation
	  given in algorithm, it is not taken in program. 
	  
	  It is recommanded to take the example in which last character of string is
	  unique or not having internally 'lab' repetition at last. 
	  
		i.e., abracadabrarrarrad	//valid example
			  aaaaaaaaaaaaaaaaa	//invalid example -> will cause std::out_of_range
			  aaaaaaaaaaaaaaaaab	//valid 	  
        abracadabrarrarra //invalid example ->will cause std::out_of_range

	2)Use special character in place of space.
	
	Prerequisites:
	
	1)	sb_size>0 and lab_size>0 	
  
  
  
  Explanation:
  
  1)This code takes window size and sb size as input. It calculates lab_size by window_size-sb_size.
  2)Initially characters are filled upto lab size. Then it takes in sb by moving the frame.
  3)It gives output as :  <poisition of repetition, number of characters which are repeated, the next character of code>
  4)It includes internal repetition of lab.
  
  
  Sample input:
    
    Enter window size and sb size:13 7

    Enter the string : abracadabrarrarrad
 

Sample output:

    string s1:abracadabrarrarrad
    length of s1:18

    < 0 , 0 , c(a ) >
    < 0 , 0 , c(b ) >
    < 0 , 0 , c(r ) >
    < 3 , 1 , c(c ) >
    < 2 , 1 , c(d ) >
    < 7 , 4 , c(r ) >
    < 3 , 5 , c(d ) >  
    
    decoding str:abracadabrarrarrad
    length of decoding_str:18
