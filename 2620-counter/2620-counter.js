/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function(...args) {
        var cnt=n;
        n=n+1;
        return cnt;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */