使用ゲームエンジン：UE5.3.2<br/>
使用IDE：Visual Studio2022<br/><br/>
  
【ビルド・実行には以下のプラグインを別途導入してください】<br/>
 [Visual Studio Integration Tool](https://fab.com/s/e55e0b834074)<br/>
 [Free Bone Snapper](https://fab.com/s/79a539e0b4bf)<br/>
 [Target System Component Plugin](https://fab.com/s/3929f225639d)<br/>
 [VRM4U](https://ruyo.github.io/VRM4U/)<br/><br/>

【起動方法】<br/>
・mainブランチを選択し、ページ右側の「<>Code」 > 「Download ZIP」でプロジェクトをダウンロード<br/>
・アセット名に日本語が含まれているのでこのままだとGit working setが呼ばれてビルドに失敗してしまうので、"/OriginalGame/"配下にある「Build_NoGitWorkingSet.bat」ファイルを実行し、無効化してください<br/>
  ※Gitを使用している方は「git config core.quotepath false」コマンドでGitの日本語ファイル名のエスケープ表示を切る方法でも可<br/>
・「OriginalGame.uproject」ファイルを右クリック > 「その他のオプションを確認」 > 「Generate Visual Studio project files」を実行<br/>
・生成された「OriginalGame.sln」をダブルクリックしてVisual Studioを起動し、上段の「Build」タブ > 「Build Solution」でビルドを実行<br/>
・「OriginalGame.uproject」をダブルクリックするとUEエディタが起動します<br/>
・UEエディタ内の下部「コンテンツエディタ」を開き、Content > InGame > Maps > Game_Start_Menu からゲームを開始できます<br/>
・ゲームに使用中のファイルはすべてInGameフォルダ内で管理しています<br/>
・ゲーム内の操作はゲームパッドを推奨しています（キーボードは一部操作に対して入力設定されていません）<br/><br/>

【】

【基本操作（ゲームパッド）】<br/>
 Xボタン(□ボタン)：攻撃<br/>
 Bボタン(○ボタン)：アクション(武器召喚、インタラクト)<br/>
 Aボタン(xボタン)：ジャンプ<br/>
 左トリガー1(L1)+XYBAボタンのいずれか：スキル攻撃<br/>
 右トリガー1(R1)：ドッジロール　※現在改修中<br/>
 右スティック押下(R3)：ロックオン/オフ<br/>
 スタートボタン：メニュー表示<br/><br/><br/>

効果音提供：[オトロジック](https://otologic.jp)<br/>

