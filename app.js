

let score  = 0;


function gen(){

    var img_dom = document.querySelector('.dice');
    var dom_score = document.getElementById("score");
 
    var num = Math.floor(Math.random()*6)+1 ;

    img_dom.src="dice-"+num+".png" ;

    score = score + num ;

    dom_score.textContent = "Total score : " + (score) ;

    
    
}