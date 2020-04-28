// Will debug it later maybe tomorrow. 
#include<bits/stdc++.h>
using namespace std;

struct node
{
  long lL,rL,nCloud;
};

void build_tree(int start, int end, vector<pair<long,long>> cloudCoverage, node sTree[], int index)
{
  if(start==end)
  {
      sTree[index].lL = cloudCoverage[start].first;
      sTree[index].rL = cloudCoverage[start].second;
      sTree[index].nCloud = 1;
  }
  else
  {
      int mid = (start+end)/2;
      build_tree(start,mid,cloudCoverage,sTree,2*index + 1);
      build_tree(mid+1,end,cloudCoverage,sTree,2*index + 2);

      if(sTree[2*index + 1].lL <= sTree[2*index + 2].lL)
      {
        if(sTree[2*index + 1].rL <= sTree[2*index + 2].rL)
        {
          if(sTree[2*index + 1].rL >= sTree[2*index + 2].lL)
          {
            sTree[index].lL = sTree[2*index + 2].lL;
            sTree[index].rL = sTree[2*index + 1].rL;
            sTree[index].nCloud = sTree[2*index + 1].nCloud + sTree[2*index + 2].nCloud;
          }
          else
          {
            //Ye case yaad rkhna when rL is less than lL tb aur neeche jaana hai traverse krte time, check it explicitly
            sTree[index].lL = sTree[2*index + 1].rL + 1;
            sTree[index].rL = sTree[2*index + 2].lL - 1;
            sTree[index].nCloud = 0;
          }
        }
        else
        {
           sTree[index].lL = sTree[2*index + 2].lL;
           sTree[index].rL = sTree[2*index + 2].rL;
           sTree[index].nCloud = sTree[2*index + 1].nCloud + sTree[2*index + 2].nCloud;
        }
      }
      else
      {
        sTree[index].lL = sTree[2*index + 1].lL;
        sTree[index].nCloud = sTree[2*index + 1].nCloud + sTree[2*index + 2].nCloud;
        if(sTree[2*index + 1].rL <= sTree[2*index + 2].rL)
        {
            sTree[index].rL = sTree[2*index + 1].rL;
        }
        else
        {
            sTree[index].rL = sTree[2*index + 2].rL;
        }
      }
  }
}

long perform_query( node sTree[], long cloud, int index , int sSize)
{
    if(index >= sSize)return 0;

    // cout<<"index is "<<index<<endl;
    // cout<<"cloud is "<<cloud<<endl;
    if(sTree[index].rL < sTree[index].lL)
    {
      long a = perform_query(sTree,cloud,2*index + 1,sSize);
      long b = perform_query(sTree,cloud,2*index + 2,sSize);
      return a+b;
    }
    else if(sTree[index].lL <= cloud && sTree[index].rL >= cloud)
    {
      return sTree[index].nCloud;
    }
    else
    {
      long a = perform_query(sTree,cloud,2*index + 1,sSize);
      long b = perform_query(sTree, cloud , 2*index + 2, sSize);
      return a+b;
    }
}

int main()
{
  int n; // For number of towns
  cin>>n;
  vector<long> population(n); // For population of towns
  for(int i = 0;i<n;i++)
  {
    cin>>population[i];
  }
  vector<long> townLoc(n); // For location of towns
  for(int i = 0;i<n;i++)
  {
    cin>>townLoc[i];
  }
  int m; // For number of clouds
  cin>>m;
  vector<long> cloudLoc(m); //For location of clouds
  for(int i = 0;i<m;i++)
  {
    cin>>cloudLoc[i];
  }
  vector<long> cR(m); //For range of clouds
  for(int i = 0;i<m;i++)
  {
    cin>>cR[i];
  }

  vector<pair<long,long>> cloudCoverage;
  for(int i = 0;i<m;i++)
  {
    cloudCoverage.push_back(make_pair(cloudLoc[i]-cR[i],cloudLoc[i]+cR[i])); // This store the coverage of cloud
  }
  sort(cloudCoverage.begin(),cloudCoverage.end()); // Sorting it acc to first entity

  int sSize = pow(2,ceil(log2(m)))*2-1;
  node sTree[sSize]; // Array of structures node.

  // cout<<"segment Tree ka size kya hai "<<sSize<<endl;
  // cout<<"build hone se pehle "<<endl;
  build_tree(0,m-1,cloudCoverage,sTree,0);
  // cout<<"build hone ke baad "<<endl;
  //
  // cout<<"segmentTree print krte hai "<<endl;


  // for(int i = 0;i<sSize;i++)
  // {
  //   cout<<sTree[i].lL<<" "<<sTree[i].rL<<" "<<sTree[i].nCloud<<endl;
  // }
  vector<int> townCoverageByCloud(n);
  for(int i = 0;i<n;i++)
  {
    // cout<<"i is "<<i<<endl;
    int status = perform_query(sTree,townLoc[i],0,sSize);
    // cout<<"status is "<<status<<endl;
    // cout<<"******************************************************"<<endl;
    townCoverageByCloud[i]=status;
  }

  // cout<<"printing town coverage status "<<endl;
  // for(int i = 0;i<townCoverageByCloud.size();i++)cout<<townCoverageByCloud[i]<<" ";
  // cout<<endl;

  long finalPopulation= 0; // Final Population
  long max = INT_MIN;

  // cout<<"printing population here "<<endl;
  // for(int i = 0;i< population.size();i++)cout<<population[i]<<" ";
  // cout<<endl;
  for(int i = 0;i<n;i++)
  {
    if(townCoverageByCloud[i]==0)
    {
      // cout<<"intermediate finalPopulation is "<<finalPopulation<<endl;
      finalPopulation+=population[i];
    }
    else if(townCoverageByCloud[i]==1)
    {
      if(population[i] > max) max = population[i];
    }
    else
    {
      continue;
    }
  }

// cout<<"printing final population "<<finalPopulation+max;
return finalPopulation+max;
}
