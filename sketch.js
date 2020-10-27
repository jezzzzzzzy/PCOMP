let inp;
function setup() {
  createCanvas(400,400);
  inp = createInput('');
 
}


function draw(){
  background(230);
  // hello
  textHere();
}

function textHere(){
  textSize(20);
  text(inp.value(), 0,200);
}