import unreal

class AutoAssetMover(unreal.AssetPostImport):
    def __init__(self):
        super().__init__()

    def post_import_asset(self, factory, created_object):
        asset_name = created_object.get_name()
        src_path = unreal.EditorAssetLibrary.get_path_name_for_loaded_asset(created_object)

        # 対象のアセットタイプ確認（ここでは全アセット対象）
        if not isinstance(created_object, unreal.Object):
            return

        # 移動先パス
        dst_path = "/Game/Imports/{}".format(asset_name)

        if unreal.EditorAssetLibrary.does_asset_exist(dst_path):
            print("[AutoAssetMover] Skip - Already exists:", dst_path)
            return

        moved = unreal.EditorAssetLibrary.rename_asset(src_path, dst_path)
        if moved:
            print("[AutoAssetMover] Asset moved to:", dst_path)
        else:
            print("[AutoAssetMover] Failed to move:", src_path)

# 登録
unreal.AssetToolsHelpers.get_asset_tools().register_asset_post_import(AutoAssetMover())
