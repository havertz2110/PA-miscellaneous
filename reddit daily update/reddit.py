import requests
import json

def get_reddit_posts():
    # Reddit API endpoint
    url = "https://www.reddit.com/r/cybersecurity.json?sort=new"
    
    # Set a User-Agent to avoid API rejection
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
    }
    
    try:
        response = requests.get(url, headers=headers)
        response.raise_for_status()  # Raise exception for bad status codes
        
        data = response.json()
        
        # Extract posts where url matches the criteria
        matching_urls = []
        for post in data['data']['children']:
            url = post['data'].get('url', '')
            if 'https://www.reddit.com' in url:
                matching_urls.append(url)
        
        # Print matching URLs
        for url in matching_urls:
            print(url)
            
        return matching_urls
            
    except requests.exceptions.RequestException as e:
        print(f"Error fetching data: {e}")
        return []

if __name__ == "__main__":
    get_reddit_posts()

