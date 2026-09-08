#pragma once
#define WIN32_LEAN_AND_MEAN
#include<Windows.h>

/// <summary>
/// 便利アイテム名前空間
/// </summary>
namespace HandyItem {

	namespace window {

		namespace desc {

			/// <summary>
			/// ウィンドウ作成構造体
			/// </summary>
			struct windowDesc {

				/// <summary>
				/// EXスタイル設定
				/// </summary>
				unsigned long	ex_style{};

				/// <summary>
				/// クラス名
				/// </summary>
				const wchar_t*	class_name{};

				/// <summary>
				/// ウィンドウ名
				/// </summary>
				const wchar_t*	window_name{};

				/// <summary>
				/// ウィンドウスタイル
				/// </summary>
				unsigned long	window_style{};

				/// <summary>
				/// ウィンドウのポジションX
				/// </summary>
				unsigned int	window_x{};

				/// <summary>
				/// ウィンドウのポジションY
				/// </summary>
				unsigned int	window_y{};

				/// <summary>
				/// ウィンドウの横幅
				/// </summary>
				unsigned int	width_{};

				/// <summary>
				/// ウィンドウの縦幅
				/// </summary>
				unsigned int	height_{};

				/// <summary>
				/// 親ウィンドウ
				/// </summary>
				HWND			pearent_{};

				/// <summary>
				/// ウィンドウメニュー
				/// </summary>
				HMENU			h_menu{};

				/// <summary>
				/// ウィンドウインスタンス
				/// </summary>
				HINSTANCE		hInstance_{};

				/// <summary>
				/// その他
				/// </summary>
				LPVOID			lpParam_{};

				/// <summary>
				/// コンストラクタ
				/// </summary>
				windowDesc() = default;

			};
		}

		class windowBase
		{
		public:

			/// <summary>
			/// ウィンドウクラス登録関数
			/// </summary>
			/// <param name="wndclass">登録するウィンドウクラス参照</param>
			/// <returns>登録の成否</returns>
			[[nodiscard]] bool register_window(WNDCLASS& wndclass) {
				return RegisterClass(&wndclass);
			}

			[[nodiscard]] HWND create_window(desc::windowDesc& desc) {

				if (desc.ex_style == 0) {
					return CreateWindow(
						desc.class_name,
						desc.window_name,
						desc.window_style,
						desc.window_x,desc.window_y,
						desc.width_,desc.height_,
						desc.pearent_,
						desc.h_menu,
						desc.hInstance_,
						desc.lpParam_
					);
				}
				else {
					return CreateWindowEx(
						desc.ex_style,
						desc.class_name,
						desc.window_name,
						desc.window_style,
						desc.window_x, desc.window_y,
						desc.width_, desc.height_,
						desc.pearent_,
						desc.h_menu,
						desc.hInstance_,
						desc.lpParam_
					);
				}
			}

			/// <summary>
			/// ウィンドウプロシージャ関数
			/// </summary>
			/// <param name="msg">ウィンドウメッセージ</param>
			/// <param name="wParam">wParam</param>
			/// <param name="lParam">lParam</param>
			virtual void process_message(MSG msg, WPARAM wParam, LPARAM lParam) = 0;

		};
	}
}