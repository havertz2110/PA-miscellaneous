import requests
import time
import json

def get_new_posts():
    url = "https://www.reddit.com/r/AskReddit/new.json"
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
    }
    
    try:
        response = requests.get(url, headers=headers)
        data = response.json()
        posts = data['data']['children']
        
        for post in posts:
            post_data = post['data']
            print(f"New post: {post_data['title']}")
            print(f"URL: {post_data['url']}\n")
            
    except Exception as e:
        print(f"Error: {e}")

def main():
    while True:
        print("Checking for new posts...")
        get_new_posts()
        time.sleep(30)  # Check every 30 seconds

if __name__ == "__main__":
    main()