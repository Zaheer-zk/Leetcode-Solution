/**
 * @param {number[]} arr
 * @return {number}
 */
var maxTurbulenceSize = function(arr) {
    let l = 0, r = 1;
    let res = 1, prev = "";
    
    while(r < arr.length) {
        if(arr[r - 1] > arr[r] && prev != ">") {
            res = Math.max(res, r - l + 1);
            r = r + 1;
            prev=">";
        } else if(arr[r - 1] < arr[r] && prev != "<") {
            res = Math.max(res, r-l+1);
            r = r + 1;
            prev="<";
        } else {
            r = arr[r-1] == arr[r] ? r+1 : r;
            l = r-1;
            prev = "";
        }
    }
    
    return res;
};