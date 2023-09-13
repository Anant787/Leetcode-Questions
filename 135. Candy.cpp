  int n= ratings.size();
  if(n == 1) return 1;

  vector<int>num(n,1); // making all the num values to 1 shows that initially all having equal candies
  int result =0;


  for(int i=1; i<n; i++) // traversing rating array forward direction
  {
      if(ratings[i] > ratings[i-1]) // if prev rating is less than current rating, then
      {
        num[i] = num[i-1] + 1;// do increment of ith canding by 1
      }
  }
  for(int i=n-1; i>0; i--) //now we are doing the same backward i=n-1th location in array
  {  if(ratings[i-1] > ratings[i])
        {  num[i-1] = max(num[i-1], num[i] + 1); // we check maximum value from num[i-1] and num[i]+1 because we have already possibility of greater rating on either sides.
        }
  }
  for(int x: num) result+=x; // it will update the result from num array and added all the count of candy together
  
  return result;
}
