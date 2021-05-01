// mylibrary.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

#include "ListManager.h"

#include "test.h"
void Draw(ListManager<test*>* listmgr)
{
    std::cout << "データ数" << listmgr->GetObjectSize() << "\n";
    for (unsigned int i = 0; i < listmgr->GetObjectSize(); i++)
    {
        listmgr->GetObject(i)->Draw();
    }
}
int main()
{
    ListManager<test*>* listmgr;
    listmgr = new  ListManager<test*>();
    //データの追加
    for (int i = 0; i < 5; i++)
    {
        listmgr->SetObject(new test());
    }
    Draw(listmgr);

    std::cout << "\n------------------------------\n";
    //一部データの削除
    std::cout << "一部データの削除\n";
    listmgr->EraseDelete(2);
    Draw(listmgr);

    std::cout << "\n------------------------------\n";
    //データの追加
    std::cout << "データの追加\n";
    for (unsigned int i = 0; i < 3; i++)
    {
        listmgr->SetObject(new test());
    }
    Draw(listmgr);

    std::cout << "\n------------------------------\n";
    std::cout << "先頭データ" << "\n";
    listmgr->GetFrontObject()->Draw();
    std::cout << "末尾データ" << "\n";
    listmgr->GetBackObject()->Draw();
    std::cout << "\n------------------------------\n";

    //データの入れ替え
    std::cout << "データの入れ替え\n";
    listmgr->ChangeObject(2, 5);
    Draw(listmgr);
    std::cout << "\n------------------------------\n";


    std::cout << "一部データを消去してその部分に追加\n";
    listmgr->EraseAndReplace(3, new test());
    Draw(listmgr);
    std::cout << "\n------------------------------\n";

    std::cout << "同じ用のindexを取得\n";
    test* chobject = listmgr->GetObject(3);
    int objectindex = listmgr->SameObject(chobject);
    if (objectindex >= 0)
    {
        listmgr->GetObject(objectindex)->Draw();
    }
    else
    {
        std::cout << "同一objectなし\n";
    }

    std::cout << "\n------------------------------\n";
    //全要素の消去
    std::cout << "リストを消去して新しく実体化\n";
    listmgr->AllDelete();

    for (int i = 0; i < 5; i++)
    {
        listmgr->SetObject(new test());
    }
    Draw(listmgr);
    std::cout << "\n------------------------------\n";

    listmgr->AllDelete();
    delete listmgr;
    _CrtDumpMemoryLeaks();

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
