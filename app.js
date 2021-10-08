

let score  = 0;


function gen(){

    var img_dom = document.querySelector('.dice');
    var dom_score = document.getElementById("score");
 
    var num = Math.floor(Math.random()*6)+1 ;
    
    //adds shaking attribute to the dice
    img_dom.classList.add("shake");
    
    setTimeout(function(){
    //stops the shaking and changes the dice value after 500 ms
    
    img_dom.classList.remove("shake")

    img_dom.src="dice-"+num+".png" ;

    score = score + num ;

    dom_score.textContent = "Total score : " + (score) ;

    }, 500);
    
}

function restart(){
    var dom_score = document.getElementById("score");
    dom_score.textContent = "Total score :  0";
    score = 0;
}




