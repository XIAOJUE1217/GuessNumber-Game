#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "game.h"
#include <string>

using namespace ftxui;

int main(){
	auto screen = ScreenInteractive::TerminalOutput();
	GuessGame game;
	std::string input_str;
	std::string tip = "请输入1~100数字开始猜谜";
	
	auto input = Input(&input_str, "输入数字");
	auto btn_guess = Button("提交猜测", [&]{
		int num;
		try{
			num = std::stoi(input_str);
		}catch(...){
			tip = "输入非法，请输入整数";
			input_str.clear();
			return;
		}
		int res = game.check(num);
		if(res == 0){
			tip = "恭喜猜对！一共猜了"+std::to_string(game.getCount())+"次，点击重置开局";
		}else if(res ==1){
			tip = "数字偏大";
		}else{
			tip = "数字偏小";
		}
		input_str.clear();
	});
	auto btn_reset = Button("重新开局", [&]{
		game.reset();
		tip = "已重置，新数字已生成";
		input_str.clear();
	});
	
	auto comp = Container::Vertical({
		input,
		Container::Horizontal({btn_guess, btn_reset})
	});
	
	auto render = Renderer(comp, [&]{
		return vbox(
					text("C++ FTXUI 猜数字游戏 | 1~100"),
					separator(),
					text(tip)|color(Color::Blue),
					separator(),
					comp->Render()
					)|border|size(WIDTH,60);
	});
	
	screen.Loop(render);
	return 0;
}
