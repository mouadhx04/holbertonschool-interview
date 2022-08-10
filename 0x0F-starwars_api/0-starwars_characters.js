#!/usr/bin/node

const request = require('request');

try {
  const movieId = process.argv[2];
  const url = `https://swapi-api.hbtn.io/api/${movieId}/`;
  request(url, async function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const characters = JSON.parse(body).characters;
      for (const character of characters) {
        const res = await new Promise((resolve, reject) => {
          request(character, (err, res, html) => {
            if (err) {
              reject(err);
            } else {
              resolve(JSON.parse(html).name);
            }
          });
        });
        console.log(res);
      }
    }
  });
} catch (catchErr) {
  console.log(catchErr);
}