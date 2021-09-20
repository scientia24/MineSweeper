// MineSweeper.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "GameManager.hpp"
#include <conio.h>
#include <iostream>

int main()
{
	bool play = true;
	while (play) {
		auto gm = GameManager();
		gm.play();
		std::cout << "何かキーを押してください。" << std::endl;
		auto command1 = _getch();

		system("cls");

		bool replayCursol = true;
		while (true)
		{
			std::cout << "もう一度遊びますか？" << std::endl;
			std::cout << (replayCursol ? "   > Yes    NO" : "     Yes  > NO") << std::endl;

			auto command = _getch();
			system("cls");

			switch (command)
			{
			case 0xe0:
				if (command == 0xe0) {
					auto allowKey = _getch();
					switch (allowKey)
					{
					case 0x4b:
						replayCursol = true;
						break;
					case 0x4d:
						replayCursol = false;
						break;
					}
				}
				break;
			case 0x0d:
				play = replayCursol;
				break;
			default:
				break;
			}
		}
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
