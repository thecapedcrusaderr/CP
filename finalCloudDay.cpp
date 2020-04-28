#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long find_upper(long cloudLim, vector<pair<long,long>> &cityData)
{
    long citySize = cityData.size();
    long reqd = citySize;
    long start = 0, end = citySize - 1;

    while(start <= end)
    {
        long mid = (start+end)/2;
        if(cityData[mid].first == cloudLim)
        {
            reqd = mid ;
            break;
        }
        else if(cityData[mid].first > cloudLim)
        {
            reqd = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return reqd;
}

long find_lower(long cloudLim, vector<pair<long,long>> &cityData)
{
    long citySize = cityData.size();
    long reqd = citySize;
    long start = 0, end = citySize - 1;

    // cout<<"cloudLimit that came here is "<<cloudLim<<endl;
    while(start <= end)
    {
        long mid = (start+end)/2;
        // cout<<"the value of mid gotten is "<<mid<<endl;
        // cout<<"the value at mid we have is "<<cityData[mid].first<<endl;
        if(cityData[mid].first == cloudLim)
        {
            reqd = mid ;
            break;
        }
        else if(cityData[mid].first > cloudLim)
        {
            end = mid - 1;
        }
        else
        {
            reqd = mid;
            start = mid + 1;
        }
    }
    return reqd;
}

int main()
{

long n; cin>>n;
vector<long> p(n);
vector<long> x(n);
for(long i = 0;i<n;i++)cin>>p[i];
for(long i = 0;i<n;i++)cin>>x[i];
long m; cin>>m;
vector<long> y(m); vector<long> r(m);
for(long i = 0; i<m;i++)cin>>y[i];
for(long i = 0;i<m;i++)cin>>r[i];

vector<pair<long,long>> dummyCityData;

for(long i = 0; i<n;i++)
{
    dummyCityData.push_back(make_pair(x[i],p[i]));
}

long dummyCitySize = dummyCityData.size();

cout<<"ab jab dummy city ban hi gya hai to size nikal ke dekh lete hai "<<dummyCitySize<<endl;
sort(dummyCityData.begin(),dummyCityData.end());

vector<pair<long,long>> cityData;
long para = 0;

for(int i = 0;i<n;i++)
{
  if(i!=0)
  {
    if(dummyCityData[i].first == dummyCityData[i-1].first)
    {
      cityData[para].second += dummyCityData[i].second;
    }
    else
    {
      cityData.push_back(make_pair(dummyCityData[i].first,dummyCityData[i].second));
      para++;
    }
  }
  else
  {
    cityData.push_back(make_pair(dummyCityData[i].first,dummyCityData[i].second));
  }
}
long newCitySize = cityData.size();
cout<<"ab cities update krne ke baad kya hai size "<<newCitySize<<endl;
// sort(cityData.begin(),cityData.end());
vector<long> cityStatus(newCitySize,0);

vector<long> cloudLeft;
vector<long> cloudRight;

for(long i = 0; i < m; i++)
{
    long left = y[i]-r[i];
    long right = y[i]+r[i];

    if(left<0) left = cityData[0].first;

    long leftUpper = find_upper(left,cityData);

    if(leftUpper == newCitySize)
    {
        cloudLeft.push_back(leftUpper);
        cloudRight.push_back(leftUpper);
        cout<<"left upper is "<<leftUpper<<endl;
        cout<<"Right upper is "<<leftUpper<<endl;
        cout<<"******************************"<<endl;
        continue;
    }
    long rightUpper = find_lower(right,cityData);

    cout<<"left upper is "<<leftUpper<<endl;
    cout<<"Right upper is "<<rightUpper<<endl;
    cout<<"******************************"<<endl;

    cloudLeft.push_back(leftUpper);
    cloudRight.push_back(rightUpper);

    if(rightUpper < leftUpper) continue;
    cityStatus[leftUpper]+=1;

    if(rightUpper+1 < newCitySize)
    {
        cityStatus[rightUpper+1]-=1;
    }
}

cout<<"checking cloudLeft and cloudRight after update "<<endl;
for(long i = 0;i<m;i++)
{
    cout<<cloudLeft[i]<<" "<<cloudRight[i]<<endl;
}

vector<long> prefixArray(newCitySize,0);

for(long i = 1;i < newCitySize; i++)
{
    cityStatus[i]+=cityStatus[i-1];
}

cout<<"printing cityStatus" <<endl;
for(long i = 0; i<newCitySize;i++) cout<<cityStatus[i]<<" ";
cout<<endl;

for(long i = 0;i < newCitySize ; i++)
{
    if(i!=0)
    {
        if(cityStatus[i]==1)
        {
            prefixArray[i] = prefixArray[i-1]+cityData[i].second;
        }
        else prefixArray[i] = prefixArray[i-1];
    }
    else
    {
        if(cityStatus[i]==1)prefixArray[i]=cityData[i].second;
    }
}
cout<<"printing prefix array "<<endl;
for(long i = 0; i< newCitySize ; i++) cout<<prefixArray[i]<<" ";
cout<<endl;

long population = 0, maxm = 0;

for(long i = 0; i < m;i++)
{
    cout<<"printing cloudLeft and cloudRight inside "<<endl;
    cout<<cloudLeft[i]<<" "<<cloudRight[i]<<endl;

    if(cloudLeft[i] > cloudRight[i]) continue;
    else if(cloudLeft[i] == newCitySize) continue;
    else if(cloudRight[i]+1 > newCitySize)
    {
        if(cloudLeft[i]==0)
        {
          if(prefixArray[newCitySize-1] > maxm) maxm=prefixArray[newCitySize-1];
        }
        else
        {
            if(prefixArray[newCitySize-1]-prefixArray[cloudLeft[i]-1] > maxm)
            {
                maxm = prefixArray[newCitySize-1]-prefixArray[cloudLeft[i]-1];
            }
        }
    }
    else
    {
        if(cloudLeft[i]==0)
        {
         if(prefixArray[cloudRight[i]] > maxm) maxm = prefixArray[cloudRight[i]];
        }
        else
        {
         if(prefixArray[cloudRight[i]]-prefixArray[cloudLeft[i]-1] > maxm )
         {
            maxm = prefixArray[cloudRight[i]] - prefixArray[cloudLeft[i]-1];
         }
        }
    }
}
cout<<"newCitySize kya hai "<<newCitySize<<endl;
cout<<"maxm value we have got is "<<maxm<<endl;

for(long i = 0;i<newCitySize;i++)
{
    if(cityStatus[i]==0) population+=cityData[i].second;
}
// cout<<"yahan aa rha hai kya "<<endl;
// cout<<"final value we have got is "<<population+maxm<<endl;
// return population+maxm;
cout<<"Final Answer is "<<population+maxm;

}
