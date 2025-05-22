import unreal

# エディタから直接呼び出せるようにするためのクラス定義
@unreal.uclass()
class AssetMoverUtility(unreal.GlobalEditorUtilityBase):
    
    # 静的関数として、複数アセットを Imports フォルダへ移動
    @unreal.ufunction(static=True)
    def move_selected_assets_to_imports():
        selected_assets = unreal.EditorUtilityLibrary.get_selected_assets()

        if not selected_assets:
            unreal.log_warning("[AutoAssetMover] No assets selected.")
            return

        for asset in selected_assets:
            asset_path = unreal.EditorAssetLibrary.get_path_name_for_loaded_asset(asset)
            asset_name = asset.get_name()
            dst_path = f"/Game/Imports/{asset_name}"

            if unreal.EditorAssetLibrary.does_asset_exist(dst_path):
                unreal.log_warning(f"[AutoAssetMover] Already exists: {dst_path}")
                continue

            success = unreal.EditorAssetLibrary.rename_asset(asset_path, dst_path)
            if success:
                unreal.log(f"[AutoAssetMover] Moved to: {dst_path}")
            else:
                unreal.log_error(f"[AutoAssetMover] Failed to move: {asset_path}")

# 🔽 これが大事！
# 名前付きでクラスをグローバルに公開することで、Blueprint からも呼び出せる
globals()["AssetMoverUtility"] = AssetMoverUtility
