/* 2022-12-21
* baekjoon 13460
* ������ ����ũ��� N, ���� ũ��� M, 1X1 ũ���� ĭ���� �������� ����
* ���� �ٱ� ��, ���� ��� #���� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�.
* ���� ������ �Ķ� ������ �� �� ĭ�� �����ϰ�, ������ ��ǥ�� ���� ������ �������� ������ ���̴�.
* 
* ������ ������ �ǵ帱 ���� ����, �߷����� �̸����� ������ �Ѵ�.
* ����, ������, ����, �Ʒ��� �� �������� ����� �� �ִ�.
* 
* �� ���ۿ��� ������ ���ÿ� �����δ�. �Ķ� ������ ���ۿ� ������ ����, ���ÿ� �� ������ ���ۿ� ������ ����
* 
* ������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
* 
* �Է�) N, M (3<=N, M<=10),
*		N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ� (.�� ��ĭ, #�� ��, o�� ����, R�� ���� ����, B�� �Ķ� ����
* 
* ���) �ּ� �� �� ���� ���� �� �ִ��� ���, ���� 10�� ���Ϸ� �������� ���� �� ������ -1
*/

// R�� ��ġ�� �ľ��ؼ�
// �� �� �ִ� ���� ������ ���� (���� �Ѵ� �� �� �ִٸ�..? (�� ���� �� �𸣰ڳ�..))
// �� �������� �� ĭ�� R�� B�� ���������鼭
// R�� ���̻� �� ���� ������ �ٽ� ������ ����

#include <iostream>
using namespace std;

int main()
{
	// N, M �ޱ�
	int N = 0;
	int M = 0;
	cin >> N >> M;

	// �����Ҵ� �ؾߵǳ�...
	// ���� N, �� ���� M��
	char** board = new char*[N];

	for (int n = 0; n < N; n++)
	{
		board[n] = new char[M];
	}

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			cin >> board[n][m];
		}
	}
		
	// R�� ��ġ�� �ľ��ؼ�
	int Rx = 0;
	int Ry = 0;
	int Bx = 0;
	int By = 0;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (board[n][m] == 'R') 
			{
				Rx = m;
				Ry = n;
			}

			if (board[n][m] == 'B')
			{
				Bx = m;
				By = n;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		// �� �� �ִ� ���� ������ ���� (���� �Ѵ� �� �� �ִٸ�..? (�� ���� �� �𸣰ڳ�..))
		// ��, �Ʒ�, ����, ������ ��� �ľ� (u, d, l, r)
		char direction = 'n';

		// u
		// ���� �� �� �ְ�, ���� direction�� d�� �ƴ� �� (�ٽ� ���ư��� �ʱ� ����) u���ιٲٱ�
		if (board[Rx][Ry - 1] == '.' && direction != 'd')
			direction = 'u';

		// d
		else if (board[Rx][Ry + 1] == '.' && direction != 'u')
			direction = 'd';

		// l
		else if (board[Rx - 1][Ry] == '.' && direction != 'r')
			direction = 'l';

		// r
		else if (board[Rx + 1][Ry] == '.' && direction != 'l')
			direction = 'r';

		// none : #�̰ų� o�̰ų�..?
		else
			direction = 'n';


		// �� �������� �� ĭ�� R�� B�� ���������鼭
		switch (direction)
		{
		case 'u':
			while (true) {
				if (board[Rx][Ry - 1] == 'O') {
					direction = 'o';
					break;
				}

				if (board[Rx][Ry - 1] == '.')
				{
					board[Rx][Ry - 1] = 'R';
					board[Rx][Ry] = '.';
					Ry -= 1;

					if (board[Bx][By - 1] == '.')
					{
						board[Bx][By - 1] = 'B';
						board[Bx][By] = '.';
						By -= 1;
					}
				}

				else
				{
					direction = 'n';
					break;
				}
			}
			break;
		case 'd':
			while (true) {
				if (board[Rx][Ry + 1] == 'O') 
				{
					direction = 'o';
					break;
				}

				if (board[Rx][Ry + 1] == '.') 
				{
					board[Rx][Ry + 1] = 'R';
					board[Rx][Ry] = '.';
					Ry += 1;
					if (board[Bx][By + 1] == '.')
					{
						board[Bx][By + 1] = 'B';
						board[Bx][By] = '.';
						By += 1;
					}
				}

				else
				{
					direction = 'n';
					break;
				}
			}
			break;
		case 'l':
			while (true)
			{
				if (board[Rx - 1][Ry] == 'O')
				{
					direction = 'o';
					break;
				}

				if (board[Rx - 1][Ry] == '.')
				{
					board[Rx - 1][Ry] = 'R';
					board[Rx][Ry] = '.';
					Rx -= 1;
					if (board[Bx - 1][By] == '.')
					{
						board[Bx - 1][By] = 'B';
						board[Bx][By] = '.';
						Bx -= 1;
					}
				}

				else
				{
					direction = 'n';
					break;
				}
			}
			break;
		case 'r':
			while (true)
			{
				if (board[Rx + 1][Ry] == 'O')
				{
					direction = 'o';
					break;
				}

				if (board[Rx + 1][Ry] == '.') {
					board[Rx + 1][Ry] = 'R';
					board[Rx][Ry] = '.';
					Rx += 1;
					if (board[Bx + 1][By] == '.')
					{
						board[Bx + 1][By] = 'B';
						board[Bx][By] = '.';
						Bx += 1;
					}
				}
				else
				{
					direction = 'n';
					break;
				}
			}
			break;
		default:
			break;
		}

		
		// R�� ���̻� �� ���� ������ �ٽ� ������ ����
	}

	for (int n = 0; n < N; n++)
		delete[] board[n];
	delete[] board;
}