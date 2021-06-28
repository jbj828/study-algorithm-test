process.stdin.resume();
process.stdin.setEncoding('utf8');

var stdin = '';
process.stdin
  .on('data', function (chunk) {
    const enterSep = chunk.split('\n');
    const setting = enterSep[0];
    const pricesString = enterSep[1];
    const settingSep = setting.split(' ');
    const pricesSep = pricesString.split(' ');
    let A = settingSep[1];
    let B = settingSep[2];

    const prices = [];
    let result = 0;
    pricesSep.forEach((el) => {
      prices.push(Number(el));
    });

    prices.sort((a, b) => b - a);

    prices.forEach((price) => {
      if (price > 2000 && A > 0) {
        result += price * 0.95;
        A--;
      } else if (price >= 1000 && B > 0) {
        result += price - 100;
        B--;
      } else if (A > 0) {
        result += price * 0.95;
        A--;
      } else {
        result += price;
      }
    });
    stdin = result.toString(10);
  })
  .on('end', function () {
    var lines = stdin.trim().split('\n');
    for (var i = 0; i < lines.length; i++) {
      process.stdout.write(lines[i]);
    }
  });

/*
  13 5 5
900 600 700 600 2000 2300 1600 500 2800 1500 1900 2200 2500
*/
