#include <iostream>
#include<string.h>
using namespace std;

int lengthOfLongestSubstring(string s) {

	int head = 0,tail = 0;   //for traversing
	int maxlen = 0;     //maxlen
	int finalHead = 0,finalTail=0;    // for printing the string having max length
	int hash[1000];
	memset(hash,-1,sizeof(hash));
	int l = s.size();
	/*
	we will find it by taking a window whose starting and end index are =[head...tail]
	*/
	while( tail < s.size() ){

		if(hash[s[tail]] < head )  //new character found ..
		/*
		if index stored in hash is less than current index of the same character then we don't need to worry . treat it as new character and overrite the new index
		example hash[a]==3
		and head ==5
		and at tail==9 we found character 'a'
		then  hash[a] < head  ... so character occurs first time in window [head...tail]
		so update new index of character

		window [head...tail]  =  [5...9]
		*/
		{
			hash[s[tail]] = tail;
			tail++;
		}
		else {							//char already in hash
			if(maxlen < tail-head){     //update maxlen
				maxlen=tail-head;
				finalTail=tail-1;
				finalHead=head;
			}
			head = hash[s[tail]]+1;     //new value of head is one index more than repeated value
			/*
			let say head==4
			and hash[s[tail]]==7
			and tail ==10
			new head will be 8 i.e. hash[s[tail]] +1
			so our new window [head...tail] = [8...10]
			*/

		}
	}

	if(maxlen < tail-head){
		maxlen=tail-head;
		finalTail=tail-1;
		finalHead=head;     //you can print the string using final head and final tail values
	}


    return maxlen;
}


int main() {
	string s="abaceaafjkk";
	cout<< lengthOfLongestSubstring(s)<<endl;
	return 1;
}

