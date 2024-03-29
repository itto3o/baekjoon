/* 2022-12-21
* baekjoon 13460
* 左球税 室稽滴奄澗 N, 亜稽 滴奄澗 M, 1X1 滴奄税 牒生稽 蟹刊嬢閃 赤製
* 亜舌 郊甥 楳, 伸精 乞砧 #生稽 厳粕閃 赤壱, 左球拭澗 姥雇戚 馬蟹 赤陥.
* 察娃 姥十引 督空 姥十戚 唖 廃 牒聖 託走馬壱, 惟績税 鯉妊澗 察娃 姥十聖 姥雇生稽 皐鎧澗 依戚陥.
* 
* 姥十聖 謝生稽 闇球険 呪澗 蒸壱, 掻径生稽 戚軒煽軒 閏形醤 廃陥.
* 図楕, 神献楕, 是楕, 焼掘楕 革 号狽生稽 奄随析 呪 赤陥.
* 
* 唖 疑拙拭辞 因級精 疑獣拭 崇送昔陥. 督空 姥十戚 姥雇拭 匙走檎 叔鳶, 疑獣拭 砧 姥十戚 姥雇拭 匙閃亀 叔鳶
* 
* 左球税 雌殿亜 爽嬢然聖 凶, 置社 護 腰 幻拭 察娃 姥十聖 姥雇聖 搭背 皐馨 呪 赤澗走 姥馬澗 覗稽益轡聖 拙失馬獣神.
* 
* 脊径) N, M (3<=N, M<=10),
*		N鯵税 匝拭 左球税 乞丞聖 蟹展鎧澗 掩戚 M税 庚切伸 (.精 朔牒, #精 混, o澗 姥雇, R精 察娃 姥十, B澗 督空 姥十
* 
* 窒径) 置社 護 腰 幻拭 皐馨 呪 赤澗走 窒径, 幻鉦 10腰 戚馬稽 崇送食辞 皐馨 呪 蒸生檎 -1
* 
* 2023-04-27
* 森薦澗 陥 梅澗汽
* 7%? 拭辞 堂携柔艦陥 銀
* 遭促 砺什闘追戚什 弘嬢左壱 粛革..
*/

// R, B澗 乞砧 4号狽 爽是 廃牒税 雌殿研 握壱赤壱,
// 嬢巨稽 奄随戚窮 .戚 赤澗 号狽生稽 奄随戚奄(奄随心陥檎 count +1)
// 雌殿研 痕鉢馬澗 go 敗呪 4鯵, (lrud)
// 牌雌 R掻宿, R胡煽 崇送戚奄
// 
// 1. 析舘 R, B税 葵聖 室特馬壱
// 2. R聖 奄層生稽 .生稽 戚疑馬奄(.戚 砧鯵虞檎..? 析舘 森薦拭澗 蒸澗汽 設 乞牽畏革) けず 焼掘櫛 業旭戚 源背 せせ
// 混拭 採禦粕辞 号狽聖 郊蝦凶原陥 count+1

// R税 是帖研 督焦背辞
// 哀 呪 赤澗 掩税 号狽聖 舛敗 (幻鉦 却陥 哀 呪 赤陥檎..? (戚 井酔澗 設 乞牽畏革..))
// 益 号狽生稽 廃 牒梢 R引 B研 崇送食亜檎辞
// R戚 希戚雌 哀 員戚 蒸生檎 陥獣 号狽聖 識澱

#include <iostream>
using namespace std;

class Marble
{
public :
	// (0,0)精 図楕 是
	int x; //x亜 亜稽,(m) 楳
	int y; // y亜 室稽(n) 伸

	Marble() {
		this->x = 0;
		this->y = 0;
	}

	int go_up(char** board)
	{
		// 郊蝦是帖亜 .戚暗蟹 O析凶幻 崇送戚奄
		// 焼原 食奄辞 馬澗惟 焼艦虞 1牒梢 崇送食醤 砺什闘追戚什亀 搭引馬走 省聖猿...
		// 侯虞 匂奄 せさせ
		char change = board[this->y - 1][this->x];
		while (change == '.' || change == 'O')
		{
			// O達紹生檎 切重精 .生稽 郊荷奄
			if (change == 'O') 
			{
				board[this->y][this->x] = '.';
				return 1;
			}

			// .戚櫛 切重 是帖櫛 郊荷奄
			char temp = board[this->y][this->x];
			board[this->y][this->x] = change;
			board[this->y - 1][this->x] = temp;

			this->y--;
			change = board[this->y - 1][this->x];
		}
		return 0;
	}

	int go_down(char** board)
	{
		char change = board[this->y + 1][this->x];
		while (change == '.' || change == 'O')
		{
			
			if (change == 'O')
			{
				board[this->y][this->x] = '.';
				return 1;
			}

			char temp = board[this->y][this->x];
			board[this->y][this->x] = change;
			board[this->y + 1][this->x] = temp;

			this->y++;
			change = board[this->y + 1][this->x];
		}
		return 0;
	}

	int go_left(char** board)
	{
		char change = board[this->y][this->x - 1];
		while (change == '.' || change == 'O')
		{
			if (change == 'O')
			{
				board[this->y][this->x] = '.';
				return 1;
			}

			char temp = board[this->y][this->x];
			board[this->y][this->x] = change;
			board[this->y][this->x - 1] = temp;

			this->x--;
			change = board[this->y][this->x - 1];
		}
		return 0;
	}

	int go_right(char** board)
	{
		char change = board[this->y][this->x + 1];
		while (change == '.' || change == 'O')
		{
			if (change == 'O')
			{
				board[this->y][this->x] = '.';
				return 1;
			}
			char temp = board[this->y][this->x];
			board[this->y][this->x] = change;
			board[this->y][this->x + 1] = temp;

			this->x++;
			change = board[this->y][this->x + 1];
		}
		return 0;
	}
};

/* 陥献 cpp督析拭辞 main戚 掻差識情 鞠醸陥壱 彊辞
int main()
{
	Marble* R = new Marble();
	Marble* B = new Marble();

	// count, 岩
	int count_ans = 0;

	// N, M 閤奄
	int N = 0;
	int M = 0;
	cin >> N >> M;

	// 疑旋拝雁 背醤鞠革...
	// 楳戚 N, 楳 原陥 M梢
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

	//for (int n = 0; n < N; n++)
	//{
	//	for (int m = 0; m < M; m++)
	//		cout << "(" << n << "," << m << "), " << board[n][m] << "\t";
	//	cout << endl;
	//}

	// R, B, O 是帖 督焦
	int Ox = 0, Oy = 0;
	// n戚 雌馬, y, m戚 x
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (board[n][m] == 'R')
			{
				//cout << n << m;
				R->y = n;
				R->x = m;
			}

			if (board[n][m] == 'B')
			{
				//cout << n << m;
				B->y = n;
				B->x = m;
			}

			if (board[n][m] == 'O')
			{
				//cout << n << m;
				Oy = n;
				Ox = m;
			}
		}
	}

	// O猿走税 置旋 井稽?
	// け?ぉ... 析舘 R, B税 是帖研 持唖背辞 崇送戚形澗 号狽生稽 希 笛 楕聖 胡煽 崇送戚切
	// 焼 崇送戚檎辞 葵亀 郊蚊醤鞠革
	// 焼観亜, .戚櫛 R戚櫛 郊蚊醤鞠革 しし

	// .引 ., .引 O戚 赤陥檎?
	// O人税 x, y研 魚閃辞 酔識旋生稽 拝 呪 赤亀系..?
	// 酔識授是..?研 幻級嬢醤馬蟹
	char priority = 'o';

	// 託税 薦咽(-号走)税 葵戚 希 笛 葵聖 酔識旋生稽 敗呪叔楳馬亀系?
	if (((Ox - R->x) * (Ox - R->x)) > ((Oy - R->y) * (Oy - R->y)))
	{
		priority = 'x';
	}
	else
		priority = 'y';



	//走蟹紳 掩聖 照亜惟 拝 呪 赤澗 号狛?
	// direction聖 幻級嬢辞 薄仙 穐揮 号狽戚虞檎 益撹 continue;
	// 悦汽 鋼球獣 及稽 亜醤馬澗 雌伐戚虞檎?
	// 穐澗汽 3号狽戚 厳粕赤澗暗檎...

	// 爽是拭 .(戚蟹 O)戚 砧鯵 赤陥檎 direction生稽 鋼企号狽生稽 亜走 省惟 敗,
	// 馬蟹屍戚虞檎 益 掩稽 哀 呪 赤亀系
	char direction = 'o';
	int R_result = -1;
	int B_result = -1;

	while (R_result != 1 && count_ans <= 10)
	{
		//for (int n = 0; n < N; n++)
		//{
		//	for (int m = 0; m < M; m++)
		//		cout << "(" << n << "," << m << "), " << board[n][m] << "\t";
		//	cout << endl;
		//}

		// R税 爽是研 詞縄左壱, 崇送析 号狽戚 赤陥檎 益楕生稽 崇送戚奄
		char R_up = board[R->y - 1][R->x];
		char R_down = board[R->y + 1][R->x];
		char R_left = board[R->y][R->x - 1];
		char R_right = board[R->y][R->x + 1];

		// 繊 鯵呪
		int pointCount = 0;
		// case庚税 if庚拭 隔壱 粛嬢亀 刃混廃 鯵呪研 乞牽艦猿...
		if ((R_left == '.' || R_left == 'O'))
			pointCount++;
		if ((R_right == '.' || R_right == 'O'))
			pointCount++;
		if ((R_up == '.' || R_up == 'O'))
			pointCount++;
		if ((R_down == '.' || R_down == 'O'))
			pointCount++;

		// 哀 呪 赤澗 掩戚 馬蟹檎 direction 段奄鉢 ==> 陥獣 宜焼哀 呪 赤亀系
		if (pointCount == 1)
			direction = 'o';

		// priority亜 x檎 left, right研 胡煽 叔楳
		// 嬢胸惟 馬窮 坪球 掻差戚 析嬢蟹革... 嬢怯馬走
		switch (priority)
		{
		case 'x':
			if (direction != 'r' && (R_left == '.' || R_left == 'O')) {
				if (R->x > B->x)
				{
					B_result = B->go_left(board);
					R_result = R->go_left(board);
				}

				else {
					R_result = R->go_left(board);
					B_result = B->go_left(board);
				}

				count_ans++;
				direction = 'l';
				continue;
			}

			if (direction != 'l' && (R_right == '.' || R_right == 'O')) {
				if (R->x < B->x)
				{
					B_result = B->go_right(board);
					R_result = R->go_right(board);
				}

				else {
					R_result = R->go_right(board);
					B_result = B->go_right(board);
				}

				count_ans++;
				direction = 'r';
				continue;
			}

			if (direction != 'd' && (R_up == '.' || R_up == 'O')) {
				if (R->y > B->y)
				{
					B_result = B->go_up(board);
					R_result = R->go_up(board);
				}

				else {
					R_result = R->go_up(board);
					B_result = B->go_up(board);
				}
				count_ans++;
				direction = 'u';
				continue;
			}

			if (direction != 'u' && (R_down == '.' || R_down == 'O')) {
				if (R->y < B->y)
				{
					B_result = B->go_down(board);
					R_result = R->go_down(board);
				}

				else {
					R_result = R->go_down(board);
					B_result = B->go_down(board);
				}
				count_ans++;
				direction = 'd';
				continue;
			}
			break;

		case 'y' :
			if (direction != 'd' && (R_up == '.' || R_up == 'O')) {
				if (R->y > B->y)
				{
					B_result = B->go_up(board);
					R_result = R->go_up(board);
				}

				else {
					R_result = R->go_up(board);
					B_result = B->go_up(board);
				}
				count_ans++;
				direction = 'u';
				continue;
			}

			if (direction != 'u' && (R_down == '.' || R_down == 'O')) {
				if (R->y < B->y)
				{
					B_result = B->go_down(board);
					R_result = R->go_down(board);
				}

				else {
					R_result = R->go_down(board);
					B_result = B->go_down(board);
				}
				count_ans++;
				direction = 'd';
				continue;
			}
			if (direction != 'r' && (R_left == '.' || R_left == 'O')) {
				if (R->x > B->x)
				{
					B_result = B->go_left(board);
					R_result = R->go_left(board);
				}

				else {
					R_result = R->go_left(board);
					B_result = B->go_left(board);
				}
				count_ans++;
				direction = 'l';
				continue;
			}

			if (direction != 'l' && (R_right == '.' || R_right == 'O')) {
				if (R->x < B->x)
				{
					B_result = B->go_right(board);
					R_result = R->go_right(board);
				}

				else {
					R_result = R->go_right(board);
					B_result = B->go_right(board);
				}
				count_ans++;
				direction = 'r';
				continue;
			}
			break;
		default:
			break;
		}
	}

	if ((R_result == 1 && B_result == 1) || count_ans > 10)
		cout << -1;
	else
		cout << count_ans;

	for (int n = 0; n < N; n++)
		delete[] board[n];
	delete[] board;
} */