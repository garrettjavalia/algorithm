pub fn h_index(citations: Vec<i32>) -> i32 {
    let mut newCitations = citations.clone();
    newCitations.sort_unstable_by(|a, b| b.cmp(a));
    let mut h: i32 = 0;
    for (i, &value) in newCitations.iter().enumerate() {
        if value > i as i32 {
            h = i as i32 + 1;
        } else {
            break;
        }
    }
    return h;
}

fn main() {
    let citations = vec![3, 0, 6, 1, 5];
    let result = h_index(citations);
    println!("{}", result);
}
