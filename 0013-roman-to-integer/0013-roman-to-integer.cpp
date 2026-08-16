class Solution {
public:
    int romanToInt(string s) {
      int sum=0;
      int j=1;
        for(int i=0 ; i<s.size() ; i++ )
        {
            bool hasNext = (j < s.size());
            if( s[i]=='I')
            {
            if(hasNext && (s[j]=='L' || s[j]=='C' || s[j]=='D' || s[j]=='M')) sum=sum+1;

            else if(hasNext && s[j]=='V')
            { sum=sum+4;
            i++; j++;}

                        else if(hasNext && s[j]=='X') 
                        {sum=sum+9;
                        i++; j++;}
                        else sum=sum+1;


            }


           else if(s[i]=='X')
            {
            if(hasNext && (s[j]=='D' || s[j]=='M')) sum=sum+10;

            else if(hasNext && s[j]=='L') 
            {sum=sum+40;
            i++; j++;}
                        else if(hasNext && s[j]=='C') 
                        {sum=sum+90;
                        i++; j++;}
                        else sum=sum+10;


            }


            
            else if(s[i]=='C')
            {
            

            if(hasNext && s[j]=='D') 
            {sum=sum+400;
            i++; j++;}
                        else if(hasNext && s[j]=='M') 
                        {sum=sum+900;
                        i++; j++;}
                        else sum=sum+100;


            }

            else if (s[i]=='V') sum=sum+5;
                      else if (s[i]=='L') sum=sum+50;
                      else if (s[i]=='D') sum=sum+500;
                         else if (s[i]=='M') sum=sum+1000; 
                         j++;
            
        }
        return sum;
    }
};