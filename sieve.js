const getPrime = upperBound => {
    const t0 = performance.now();
    let list = new Array(upperBound).fill(true);
    const m = Math.sqrt(upperBound);
    for(let i=2; i<=m; ++i){
                   if(list[i]){
                       for(let j=2; i*j<upperBound; ++j){
                            list[i * j] = false;
                       }
                   }
            }
    const t1 = performance.now();
    return t1-t0;
}