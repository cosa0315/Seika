$(function(){
	let count = 0;//カウント用
	setInterval(function(){
		if(count >= 2){//３枚目だったら
			$(".slide ul").animate({"left":"0"},"slow");
			count = 0;
		}else{//１枚目か２枚目
			count = count + 1;//count++;
			$(".slide ul").animate({"left":"-=1000px"},"slow");
		}
	},3000);

	
	
});
/*スマートフォン用のスライド*/
$(function(){
	let count = 0;//カウント用
	setInterval(function(){
		if(count >= 2){//３枚目だったら
			$(".spslide ul").animate({"left":"0"},"slow");
			count = 0;
		}else{//１枚目か２枚目
			count = count + 1;//count++;
			$(".spslide ul").animate({"left":"-=600px"},"slow");
		}
	},1800);

	
	
});
$(function(){
	//セレクタ。メソッド(引数)
	$(".spbutton").click(function(){
		$(".spnav").slideToggle(1000);//1000ミリ秒("display","block")
	});
	
	
});
$(function(){
	$(".setumei").click(function(){
		$("body").append('<div class="bg">');//中で”を使っている場合外は'になる
		$(".bg").css("display","none");//表示消す
		$(".bg").append('<div class="spphoto">');
		$(".spphoto").append('<img>');
		$(".spphoto img").attr("src",$(this).attr("href"));
		$(".spphoto img").attr("alt","spphoto");
		$(".bg").fadeIn(500);
		$(".bg").click(function(){
			$(".bg").fadeOut(function(){
				$(this).remove();//タグを消す			 
			});
			
	});
		return false;//aの機能を消す
	});
	
	
	
});