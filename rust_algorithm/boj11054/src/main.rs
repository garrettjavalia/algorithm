fn main() {
    // Your code here

    // 정수 n을 표준입력에서 받는 코드
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let mut n: i32 = n.trim().parse().unwrap();

    // 공백으로 구별된 n개의 정수를 배열에 입력받는 코드
    let mut arr = String::new();
    std::io::stdin().read_line(&mut arr).unwrap();
    let arr: Vec<i32> = arr.split_whitespace().map(|x| x.parse().unwrap()).collect();

    // arr을 뒤집은 배열을 구한다.
    let mut arr2 = arr.clone();
    arr2.reverse();

    let lisArr: Vec<i32> = lis(arr);
    let reversedList: Vec<i32> = lis(arr2);
    let mut lds: Vec<i32> = reversedList.clone();
    lds.reverse();

    // lis와 lds의 값을 더한 배열을 구한다
    let mut sum: Vec<i32> = [].to_vec();
    for i in 0..n as usize {
        sum.push(lisArr[i] + lds[i] - 1); // 증가수열과 감소수열이 중복되므로 1을 뺀다.
    }
    // sum배열의 최대값을 구한다.
    let max = sum.iter().max().unwrap();
    // 최대값을 출력한다
    println!("{}", max);
}

// 정수의 배열을 입력받고 해당 배열과 같은 크기의 정수 배열을 돌려주는 함수
fn lis(arr: Vec<i32>) -> Vec<i32> {
    let mut lis: Vec<i32> = [].to_vec();
    // lis 배열에 1을 넣는다
    lis.push(1);

    // arr의 1번 인덱스부터 마지막 인덱스까지 반복한다
    for i in 1..arr.len() as usize {
        //1, 2, 3의 배열에서 최대값을 구한다
        let mut max = 1;
        for j in 0..i as usize {
            if arr[i] > arr[j] {
                max = std::cmp::max(max, lis[j] + 1);
            }
        }
        lis.push(max)
    }
    return lis;
}
