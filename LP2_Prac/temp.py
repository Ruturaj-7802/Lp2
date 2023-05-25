# import random
# import re

# greetings = [
#     "hi",
#     "hello",
#     "hi there!",
#     "hey",
#     "Greetings!"
# ]

# help_text = "How can I help you today? You can ask about our labs!"

# labs = [
#     {"name" : "LP2", "prof" : "Mrs. Joshi"},
#     {"name" : "DSBDAL", "prof" : "Mr. Kumar"},
#     {"name" : "WTL", "prof" : "Mr. Parag"},
# ]

# def get_respone(responses):
#     return random.choice(responses)

# def get_lab(name):
#     for lab in labs:
#         if name.lower() in lab['name'].lower():
#             return lab
#     return "No book available"

# def handle_input(input_text):
#     if re.search(r'\b(hi|hello|hey)\b' , input_text, re.IGNORECASE):
#         return get_respone(greetings)
    
#     if re.search(r'\b(help|support)\b', input_text, re.IGNORECASE):
#         return help_text
    
#     if re.search(r'\b(lab|labs)\b', input_text, re.IGNORECASE):
#         labName = re.search(r'\b(name)\b\s(.+)', input_text, re.IGNORECASE)
#         if labName:
#             lab = get_lab(labName.group(2))
#             if lab:
#                 return f"{lab}"