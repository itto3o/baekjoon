/*
* 2023-05-04
* 
* NXN ���簢 ����,
* ����� ��ġ�� �־�����,
* ������ ��ȭ�ڿ� ���� ���� �ִ�.
* 
* ���� �� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ����
* 
* ���� ���۽� ���� ���� �������� ��ġ, ���̴� 1, �������� ����
* �� �ʸ��� �̵�,
* �Ӹ��� ����ĭ�� ��ġ��Ų ��, ���� ĭ�� ����� �ִٸ� ����� �������� ������ �������� ����
* ����� ���ٸ� �����̸� �ٿ��� ĭ�� �����(������ ��ȭx)
* 
* �����ġ, ���� �̵���ΰ� �־��� �� ������ �� �ʿ� ��������
* 
* �Է�)
* 1. ������ ũ�� N (2<=N<=100)
* 2. ����� ���� K(0 <= K <= 100)
* (���� ũ�⺸�� Ŭ �� �ֳ�..?)
* 
* 3. K���� �ٿ��� ���� ����� ��ġ�� �־���
* ��, ��,
* ����� ��ġ�� ��� �ٸ�, 1�� 1������ ����� ����
* 4. ���� ���� ��ȯ Ƚ�� L(1<=L<=100)
* 5. L���� �ٿ� ��ȯ ����, X, C(X�ʰ� ���� �� C�� ������ 90�� ȸ��(L�Ǵ� D)
*	X <= 10,000 ������ �ڿ���, X�� �����ϴ� ������ �־���
* 
* ���)
* ù° �ٿ� ������ �� �ʿ� �������� ���
* 
* 
* ---000
* 00|0*0
* 00|*00
* 00*000
* 00|--0
* 
* ---------0
* 0****00||0
* 0000000-|0
* 0000000000
* 0000000000
* 0000000000
* 0000000000
* 0000000000
* 0000000000
* 0000000000
* 
* �ƴ� ���� ���ظ� �� ���ϰٴµ�
* ���ʿ� �����Ҷ� �ǿ��ʸ���ĭ���� 1�ʸ� ���°���
* ������ 2�ʾ����°ǰ�?
* ���� �� �ִ°ǰ� �׷�
* �׷� 1���� ��� ���̰ڳ�?
* ��� ��ġ�� �� �޶�����..?
* �ƴ� ������ ���� ��ģ����
* 
* 000000
* 0----0
* 0000|0
* 0000|0
* 0000|0
* 000000 �̷��� 7�Ƴ�?
* 
* ���� 1�ʰ� �����̶�� + ������ȯ���� 1�ʸ� ���ٸ�
* 000000
* 0--|00
* 000|00
* 000|00
* 000|00 �̷��� 8�ƴѰ�
* 000000 
* 
* // ���� ���ٸ�
* ---000
* 00|000
* 00|000
* 00|000
* 00|000
* 00|000 �̷� 9�� �ϳ�
* 
* ----000
* 000|00
* 000|00
* 000|00
* 000|00
* 000|00 8���� �� ���������� ���°Ű�, 9 ������ �� ���̳�
* 
* ���
* ���� ���������δ� ����.
* ������ Ʈ�� �ð��� 1������ �ʴ°Ͱ���.
* ������ Ʈ�� �ð��� ���� ����, ���� ���Ͽ��� 1�ʸ� ���� �ʴ� �� ����.
* 
* �ణ ������ �� �о�� ���� �ִ� �� ���⵵�ϴ�
* 
*/

#include <iostream>
#include <vector>
using namespace std;

enum {
	// �ð��������
	UP, RIGHT, DOWN, LEFT
};
struct Position
{
	int y = 0;
	int x= 0;
};

class Snake
{
public:
	int snakeLen = 1;
	Position headPosition;
	Position tailPosition;
	vector<Position> chargePosition;
	int goingDirection = RIGHT;

	void go()
	{

	}
};

int main()
{
	int N = 0;
	int K = 0;

	cin >> N;
	if (N < 2 || N > 100)
		return -1;

	int** board = new int* [N];
	for (int i = 0; i < N; i++)
		board[i] = new int[N];

	// �ʱ�ȭ(���Ѿ� �ǳ�?) ���ʿ� �ʿ䰡 �ֳ�?
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}

	cin >> K;
	if (K < 0 || K > 100)
		return -1;

	Position* apples = new Position[K];
	for (int i = 0; i < K; i++)
	{
		cin >> apples[i].y >> apples[i].x;
	}

	int L;
	if (L < 1 || L > 100)
		return -1;

	vector<int, char> transformDirection;
	int time = 0;
	char direction = 'D';
	for (int i = 0; i < L; i++)
	{
		cin >> time >> direction;
		transformDirection.push_back(time);//, direction }); //�� �̷��� �ϴ� �� �³�
		// �Ƹ��� ������ ��������� �ҷ�...
	}
	
	for (int n = 0; n < N; n++)
		delete[] board[n];
	delete[] board;
	return 0;
	return 0;
}