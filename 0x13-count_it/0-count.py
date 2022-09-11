#!/usr/bin/python3
"""  a recursive function that queries the Reddit API """
import requests
from sys import argv


def list_creator(hot_subreddits, posts, posts_len):
    """ Creates a list"""
    i = 0
    while i < posts_len:
        hot_subreddits.append(posts[i]['data']['title'])
        i += 1
    return (hot_subreddits)


def count_words(subreddit, word_list, hot_subreddits=[], after=None):
    """ a recursive function that queries the Reddit API """

    if len(argv) < 2:
        return (None)

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    header = {'User-Agent': 'python3:holberton.task:v1.0'}
    payload = {'limit': '100', 'after': after}
    request = requests.get(url, params=payload, headers=header)
    if request.status_code == 200:
        about = request.json()
        posts = about['data']['children']
        posts_len = len(posts)
        if posts_len != 0:
            (list_creator(hot_subreddits, posts, posts_len))
        else:
            None
        after = about['data']['after']
        if after is not None:
            return (count_words(subreddit, word_list, hot_subreddits, after))
        else:
            count_dict = {}
            for word in argv[2].split():
                ocurrences = 0
                for title in hot_subreddits:
                    ocurrences += title.lower().count(word.lower())
                if word.lower() not in count_dict.keys():
                    count_dict[word.lower()] = ocurrences
            count_sorted = sorted(count_dict, key=count_dict.get, reverse=True)
            for key in count_sorted:
                if count_dict[key] > 0:
                    print("{}: {}".format(key, count_dict[key]))
    else:
        return None
