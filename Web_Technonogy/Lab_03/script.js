document.getElementById("contactForm").addEventListener("submit", function (event) {
    event.preventDefault();
  
    // Clear previous feedback
    const feedback = document.getElementById("feedback");
    feedback.textContent = "";
    feedback.style.color = "red";
  
    // Reset input borders
    const inputs = document.querySelectorAll("input, textarea");
    inputs.forEach((input) => input.classList.remove("invalid"));
  
    // Get values
    const name = document.getElementById("name");
    const subject = document.getElementById("subject");
    const message = document.getElementById("message");
    const category = document.querySelector('input[name="category"]:checked');
    const contactMethods = document.querySelectorAll('input[name="contactMethod"]:checked');
  
    // Validation flags
    let isValid = true;
  
    // 1. Validate Name: not empty, only letters and spaces
    if (!/^[A-Za-z\s]+$/.test(name.value.trim())) {
      name.classList.add("invalid");
      feedback.textContent = "Name must contain only letters and spaces.";
      isValid = false;
    }
  
    // 2. Validate Subject: 5–50 characters
    else if (subject.value.trim().length < 5 || subject.value.trim().length > 50) {
      subject.classList.add("invalid");
      feedback.textContent = "Subject must be between 5 and 50 characters.";
      isValid = false;
    }
  
    // 3. Validate Message Category
    else if (!category) {
      feedback.textContent = "Please select a message category.";
      isValid = false;
    }
  
    // 4. Validate Message: at least 10 characters
    else if (message.value.trim().length < 10) {
      message.classList.add("invalid");
      feedback.textContent = "Message must be at least 10 characters long.";
      isValid = false;
    }
  
    // 5. Validate Contact Method: at least one checkbox selected
    else if (contactMethods.length === 0) {
      feedback.textContent = "Please select at least one preferred contact method.";
      isValid = false;
    }
  
    // Success
    if (isValid) {
      feedback.style.color = "green";
      feedback.textContent = "Thank you! Your message has been sent.";
      document.getElementById("contactForm").reset();
    }
  });
  