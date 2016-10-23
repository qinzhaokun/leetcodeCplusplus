public class Solution {
    public String numberToWords(int num) {
        if(num == 0) return "Zero";
        String [] l3 = {"", "Thousand", "Million", "Billion"};
        int count = 0;
        String ans = "";
        while(num != 0){
            String t = helper(num%1000); 
            ans = t.length()==0?"":(t+(count==0?"":(" " + l3[count]))) + (ans.length()==0?"":(" " + ans)); 
            num /= 1000;
            count++;
        }
        return ans;
    }
    
    String helper(int num){
        String [] l1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        String [] l2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if(num < 20) return l1[num];
        if(num < 100) return l2[num/10] + (num%10 == 0? "":(" " + l1[num%10]));
        String ans = l1[num/100] + " " + "Hundred";
        if(num%100 != 0){
            ans += " " + helper(num%100); 
        }
        return ans; 
        
    }
}
