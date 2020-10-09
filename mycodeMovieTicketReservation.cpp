#include<bits/stdc++.h>
using namespace std;

class Screen
{
    int row, col;
    vector<vector<char>> seats;
    vector<vector<int>> vacancy;
    public:

        void add_screen(vector<string> &words)
        {
          // cout<<" isme aa bhi rha hai ya nahin "<<endl;
          int n = words.size();
          row = stoi(words[2]);
          col = stoi(words[3]);

          seats.resize(row, vector<char> (col, 'N'));
          vacancy.resize(row, vector<int> (col, 1));

          vector<int> aisles;
          for(int j = 4 ; j < n ; j++)
          {
            aisles.push_back(stoi(words[j]) - 1);
            sort(aisles.begin(),aisles.end());
          }
          int aSize = aisles.size();

          for(int i = 0 ; i < row ; i++)
          {
              for(int j = 0 ; j < aSize ; j++)
              {
                  int here = aisles[j];
                  if((j%2) == 0)
                  {
                    seats[i][here] = 'E';
                  }
                  else
                  {
                    seats[i][here] = 'S';
                  }
              }
          }
          cout<<"success"<<endl;
        }

        void reserve_seat(vector<string> &words)
        {
            int r = stoi(words[2])-1;
            if(r < 0 || r >= row)
            {
              cout<<"failure"<<endl;
              return;
            }
            int n = words.size();

            for(int i = 3 ; i < n ;i++)
            {
                int here = stoi(words[i]) - 1;

                if(here < 0 || here >= col || vacancy[r][here]==0)
                {
                    cout<<"failure"<<endl;
                    return;
                }
            }

            for(int i = 3 ; i < n ; i++)
            {
                int here = stoi(words[i]) - 1;
                vacancy[r][here] = 0;
            }
            cout<<"success"<<endl;
        }

        void get_unreserved_seats(vector<string> &words)
        {
            int r = stoi(words[2])-1;
            bool hua = false;
            for(int j = 0 ; j < col ; j++)
            {
                if(vacancy[r][j]==1)
                {
                    if(!hua)
                    {
                        cout<<j+1;
                        hua = true;
                    }
                    else
                    {
                        cout<<" "<<j+1;
                    }
                }
            }
            cout<<endl;
        }

        void suggest_continuous_seats(vector<string> &words)
        {
            int nSeats = stoi(words[2]), r = stoi(words[3])-1, choice = stoi(words[4])-1;

            if( r < 0 || r >= row  ||  nSeats <= 0 || (choice+nSeats > col && choice-nSeats+1 < 0))
            {
                cout<<"none"<<endl;
                return;
            }

            // Pehle right se check krte hai
            bool pehla = false;
            if(choice+nSeats <= col)
            {
                pehla = true;
                for(int i = choice ; i < choice+nSeats ; i++)
                {
                    if(vacancy[r][i]==0)
                    {
                      pehla = false;
                      break;
                    }
                    if(seats[r][i]=='S')
                    {
                        if(i!=choice)
                        {
                          pehla = false;
                          break;
                        }
                    }
                }
            }
            if(pehla)
            {
                for(int i = choice ; i < choice + nSeats ; i++)
                {
                    if(i==choice)
                    {
                      cout<<i+1;
                    }
                    else
                    {
                       cout<<" "<<i+1;
                    }
                }
                cout<<endl;
                return;
            }

            // Now going on with the 2nd possibility
            if(choice - nSeats +1 < 0)
            {
              cout<<"none"<<endl;
              return;
            }

            int start = choice-nSeats+1;

            for(int i = start ; i <= choice ; i++)
            {
                if(vacancy[r][i]==0)
                {
                  cout<<"none"<<endl;
                  return;
                }

                if(seats[r][i]=='S')
                {
                    if(i!=start)
                    {
                      cout<<"none"<<endl;
                      return;
                    }
                }
            }

            for(int i = start ; i <= choice ; i++)
            {
                if(i==start)
                {
                  cout<<i+1;
                }
                else
                {
                  cout<<" "<<i+1;
                }
            }
            cout<<endl;
            return;
            // 2 possibility here, either starting with choice or ending with choice
        }
};

int main()
{
    string str;
    getline(cin,str);

    int n = stoi(str);

    unordered_map<string, Screen*> mapp;

    for(int i = 0 ; i < n ; i++)
    {
        getline(cin,str);
        stringstream s(str);
        string here;

        vector<string> words;
        while(s>>here)
        {
          words.push_back(here);
        }

        if(words[0]=="add_screen")
        {

            int rtemp = stoi(words[2]), ctemp = stoi(words[3]);
            if( rtemp <= 0 || ctemp <= 0 || mapp.count(words[1]))
            {
              cout<<"failure"<<endl;
              continue;
            }

            bool check = false;
            for(int i = 4 ; i < words.size(); i++)
            {
                int var = stoi(words[i]);
                if(var < 1 || var > ctemp)
                {
                  cout<<"failure"<<endl;
                  check = true;
                  break;
                }
            }
            if(check)continue;

            mapp[words[1]] = new Screen();
            mapp[words[1]]->add_screen(words);
        }
        else if(words[0]=="reserve_seat")
        {
            if(mapp.count(words[1]))
            {
                mapp[words[1]]->reserve_seat(words);
            }
            else
            {
              cout<<"failure"<<endl;
            }
        }
        else if(words[0]=="get_unreserved_seats")
        {
            if(mapp.count(words[1]))
            {
              mapp[words[1]]->get_unreserved_seats(words);
            }
            else
            {
              cout<<"failure"<<endl;
            }
        }
        else
        {
            if(mapp.count(words[1]))
            {
                mapp[words[1]]->suggest_continuous_seats(words);
            }
            else
            {
                cout<<"none"<<endl;
            }
        }
    }
    return 0;
};
