Lab Question: Build a Contact Us Form with JavaScript Validation

**Objective:**  
Create a "Contact Us" form webpage using HTML, CSS, and JavaScript. The form should allow users to send a message to a fictional company, with client-side validation to ensure all inputs meet specific criteria before submission.

**Requirements:**

1. **HTML Structure:**
   - Use semantic HTML tags (e.g., `<header>`, `<main>`, `<form>`, `<footer>`) to organize the content.
   - Include the following sections:
     - A header with a title (e.g., "Contact Us - BrightFuture Inc").
     - A short introduction (e.g., "Have a question? Reach out to us below!").
     - A `<form>` element with the following fields:
       - Name (text input, required).
       - Subject (text input, required).
       - Message Category (radio buttons with options: "Support", "Sales", "Feedback", required).
       - Message (textarea, required, minimum 10 characters).
       - Preferred Contact Method (checkboxes for "Email" and "Phone", at least one must be selected).
       - A "Send Message" button.
     - A `<div>` or `<p>` element below the form to display validation feedback.
     - A footer with a note (e.g., "© 2025 BrightFuture Inc. All inquiries welcome.").

2. **CSS Styling:**
   - Create an inviting design:
     - Set a max-width for the form (e.g., `600px`), center it, and add padding and a subtle shadow or border.
     - Style inputs, radio buttons, checkboxes, and textarea with consistent spacing and borders.
     - Use a color scheme (e.g., light background, dark text, and a warm accent like orange or green).
   - Style the "Send Message" button with a hover effect (e.g., scale slightly or change color).
   - Highlight invalid fields with a visual cue (e.g., red outline or text) when validation fails.

3. **JavaScript Validation:**
   - Add an event listener to the form’s `submit` event and prevent default submission (`event.preventDefault()`).
   - Validate the following:
     - **Name:** Must not be empty and must contain only letters and spaces (no numbers or special characters).
     - **Subject:** Must not be empty and must be between 5 and 50 characters long.
     - **Message Category:** One radio button must be selected.
     - **Message:** Must not be empty and must be at least 10 characters long.
     - **Preferred Contact Method:** At least one checkbox (Email or Phone) must be checked.
   - Display clear error messages in the feedback area when validation fails (e.g., "Please select at least one contact method").
   - Clear previous feedback before each validation check.
   - If all validations pass, show a success message (e.g., "Thank you! Your message has been sent.") instead of submitting the form.


**Submission Guidelines:**
- Submit three files: `contact-us.html`, `contact-us.css`, and `contact-us.js`.
- Test your webpage in a browser to confirm validation works and the design is intact.
- Comment your JavaScript file to explain at least 3 validation rules or implementation choices.