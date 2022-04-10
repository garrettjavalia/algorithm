class ACNode{

  parent:ACNode|null = null;
  value:string|null;
  output:string|null = null;
  failure:ACNode|null = null;
  outputLink:ACNode|null = null;
  childMap:Map<string, ACNode> = new Map();
  depth:number = 0;
  
  constructor(value:string|null){
    this.value = value;
  }

  hasChild(key:string){
    return this.childMap.get(key) !== undefined;
  }

  getChild(key:string){
    return this.childMap.get(key);
  }

  addChild(node:ACNode){
    if(node.value !== null){
      this.childMap.set(node.value, node);
      node.parent = this;
      node.depth = this.depth + 1;
      return true;
    }
    return false;
  }

}

class AhoCorasick{

  //root has no value, nor output.
  root:ACNode = new ACNode(null);

  add(pattern:string){
    let parent = this.root;
    for(let i = 0; i < pattern.length; i++){
      let c = pattern[i];
      if(!parent.hasChild(c)){
        let child = new ACNode(c);
        parent.addChild(child);
        parent = child;
      }else{
        parent = parent.getChild(c)!
      }
    }
    parent.output = pattern;
  }

  //build both of output and failure link
  buildLink(){
    let bfs:ACNode[] = [this.root];
    while(bfs.length !== 0){
      let target = bfs.shift()!;
      //루트는 원래 실패시에 자기 자신으로 가야하고, 루트의 바로 밑 자식들은 맨 앞 한 글자라서
      //무조건 빠져야 한다. 아래의 설명과 이어지는 부분이다.
      if( (target === this.root) || (target.parent === this.root)){
        target.failure = this.root;
        target.outputLink = null;
        // console.log("링크 첫 요소들 빌드", target.value, target.output, target.failure.value, target.failure.output);
      }else{
        // console.log("링크 생성중", target.value);
        //여기서 부모의 failure를 물어보는 것은 이런 의미다.
        //부모까지 이르는 경로에, 맨 앞의 한 글자는 무조건 빼고(빼지 않으면 완전히 똑같은 접미사(자기자신)을 구한다.)
        //최소한 부모까지 이어지는 경로가 있었는가? 있었다면 이제 그 경로에서 자기의 값으로 이어지는 경로가 있는지 본다.
        let failure = target.parent!.failure!;
        // console.log("실패링크 탐색중", failure.value)
        while(!failure.hasChild(target.value!) && !(failure === this.root)){
          failure = failure.failure!;
          // console.log("실패링크 탐색중 반복", failure.value)
        }
        let failureChild = failure.getChild(target.value!);
        target.failure = failureChild === undefined ? this.root : failureChild;
        // console.log("실패링크 탐색 완료", failure.value, failure === this.root)
        target.outputLink = target.failure.output !== null ? target.failure : target.failure.outputLink;
        // console.log("링크 빌드", target.value, target.output, target.failure.value, target.failure.output);
      }
      target.childMap.forEach(value => {
        bfs.push(value);
      });
    }
  }

  //문자열의 시작 위치와 문자열을 가진 배열, 배열 길이가 0이라면 일치결과 없음
  search(text:string):[number, string][]{

    let res:[number, string][] = []
    let currentNode = this.root;

    for(let i = 0; i < text.length; i++){
      let c = text[i];
      //console.log("패턴 검색 중", c)
      //갈 수 있을 때까지 혹은 루트에 갈 때까지 이동
      while(!currentNode.hasChild(c) && currentNode !== this.root){
        currentNode = currentNode.failure!;
      }
      //이동 시도
      if(currentNode.hasChild(c)){
        currentNode = currentNode.getChild(c)!;
        //console.log("글자 있어서 진행함")
      }
      //자신의 아웃펏링크는 자신이 찾은 글자들보단 짧다.
      if(currentNode.outputLink !== null){
        let outputLink:ACNode|null = currentNode.outputLink;
        while(outputLink !== null){
        // console.log(outputLink.output, "아웃풋 링크 결과 추가")
          res.push([i - outputLink.output!.length + 1, outputLink.output!]);
          outputLink = outputLink.outputLink;
          
        }
      }
      if(currentNode.output !== null){
        // console.log(currentNode.output, "아웃풋 결과 추가")
        res.push([i - currentNode.output!.length + 1, currentNode.output!]);
      }
    }
    
    return res;
  }

}

let AC = new AhoCorasick();

// let testPatterns = ["a", "ab", "c", "d", "fgi", "gi", "i", "fgii", "ii"]
// let testPatterns = ["a", "aa", "aaa", "aaaa", "aaaaa"];

// testPatterns.forEach(s => {
//   AC.add(s);
// })
// AC.buildLink();
// console.log(AC.search("abcdefghijfgiiiiiab"));
// console.log(AC.search("aaaaaaaaaa"));


let fs = require("fs")

let inputs = fs.readFileSync("/dev/stdin").toString().split("\n");
let N = parseInt(inputs[0]);
for(let i = 0; i < N; i++){
  AC.add(inputs[i + 1]);
}
AC.buildLink();
let Q = parseInt(inputs[N + 1]);
for(let i = 0; i < Q; i++){
  let test = inputs[N + 2 + i];
  if(AC.search(test).length > 0){
    console.log("YES");
  }else{
    console.log("NO");
  }
}