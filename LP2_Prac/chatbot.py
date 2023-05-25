import random
import re
# re is the Python module for working with regular expressions.
# re.IGNORECASE is a flag that makes the search case-insensitive, so that it matches both "name" and "Name"

# Define some responses
greetings = ["hi","Hello!", "Hi there!", "Hey!", "Greetings!"]
help_text = "How can I help you today? You can ask me about our books."

# Define a list of products
products = [
    {"name": "speak", "description": "Speak, published in 1999, is a young adult novel by Laurie Halse Anderson that tells the story of high school freshman Melinda Sordino.", "price": 100},
    {"name": "emma", "description": "Emma is a novel written by Jane Austen. It is set in the fictional country village of Highbury and the surrounding estates of Hartfield, Randalls and Donwell Abbey, and involves the relationships among people from a small number of families", "price": 130},
    {"name": "away", "description": "Away is the epic and intimate story of young Lillian Leyb, a dangerous innocent, an accidental heroine. When her family is destroyed in a Russian pogrom, Lillian comes to America alone, determined to make her way in a new land. ", "price": 120},
    {"name": "ash", "description": "For a book with such a provocative, potentially controversial premise, Ash is dreadfully, painfully dull and lacking in strong emotion and vibrant characters.", "price": 300}
]

# Define a function to get a random response from a list of responses
def get_response(responses):
    return random.choice(responses)

# Define a function to get a product by name
def get_product(name):
    for product in products:
        if name.lower() in product['name'].lower():
            return product
    return "no book available"

# Define a function to handle user input
# \bhello\b matches the word "hello" only if 
# it appears as a whole word, and not as part
# of another word (e.g. it matches "hello" in 
# "hello world", but not in "helloworld" or "sayhello").
def handle_input(input_text):
    # Greetings
    if re.search(r'\b(hi|hello|hey)\b', input_text, re.IGNORECASE):
        return get_response(greetings)
    # Help
    if re.search(r'\b(help|support)\b', input_text, re.IGNORECASE):
        return help_text
    # Product inquiry
    if re.search(r'\b(book|books)\b', input_text, re.IGNORECASE):
        product_name = re.search(r'\b(name)\b\s(.+)', input_text, re.IGNORECASE)
        if product_name:
            product = get_product(product_name.group(2))
            if product:
                return f"{product['name']} \n  descreption: {product['description']}  \n price: ${product['price']}"
            else:
                return "Sorry, I couldn't find that book. Can I help you with anything else?"
        else:
            return "Which book are you interested in? Please specify the name."
    # Purchase
    if re.search(r'\b(buy|purchase|order)\b', input_text, re.IGNORECASE):
        product_name = re.search(r'\b(name)\b\s(.+)', input_text, re.IGNORECASE)
        if product_name:
            product = get_product(product_name.group(2))
            if product:
                return f"Great, you have ordered {product['name']} for ${product['price']}. Please proceed to checkout."
            else:
                return "Sorry, I couldn't find that book. Can I help you with anything else?"
        else:
            return "Which book would you like to buy? Please specify the name."
        
    if re.search(r'\b(thanks|thank you)\b', input_text, re.IGNORECASE):
        return "thank you"
    if re.search(r'\b(bye)\b', input_text, re.IGNORECASE):
        print("bye good day")
        exit 
    # Default response
    return "I'm sorry, I didn't understand what you said. " + help_text
    
    

      
# Main loop to get user input and respond
print("Welcome to website!")
while True:
    user_input = input("You: ")
    bot_response = handle_input(user_input)
    print("Bot: " + bot_response)