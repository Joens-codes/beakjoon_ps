#include<iostream>
using namespace std;
int N1;
int N2;
int box[50];
int sbox[50];
class queue {
public:
	int front();
	void left();
	void right();
	int show();
};
int queue::front()
{
	int ans = box[0];
	for (int i = 0; i < N1; i++)
	{
		box[i] = box[i + 1];
	}
	N1--;
	return ans;
}
int queue::show()
{
	return box[0];
}
void queue::left()
{
	int swap;
	swap = box[0];
	for (int i = 0; i < N1-1; i++)
	{
		box[i] = box[i + 1];
	}
	box[N1 - 1] = swap;
       
}
void queue::right()
{
	int swap;
	swap = box[N1-1];
	for (int i = N1-1; i >=0; i--)
	{
		box[i] = box[i-1];
	}
	box[0] = swap;

}
void arraystart()
{
	for (int i = 0; i < N1; i++)
	{
		box[i] = i+1;
	}
}
int prof()
{   
	queue Q;
	int cnt = 0;
	for (int i = 0; i < N2; i++)
	{  
        int num;
        for(int j = 0;j<N1;j++)
        {
            if(sbox[i] == box[j])
            {
                num = j;
            }
        }
		while (1)
		{
            
			if (sbox[i] == Q.show())
			{
                Q.front();
				break;
			}
			if (num> N1 / 2)
			{
                Q.right();
            }
			else
			{
				Q.left();
			}
			cnt++;
		}

	}

		return cnt;
}
int main()
{
	
	cin >> N1;
	cin >> N2;
	int ans = 0;
	for (int i = 0; i < N2; i++)
	{
		cin >> sbox[i];
	}
	arraystart();
	ans = prof();
	cout << ans << endl;
	return 0;

}