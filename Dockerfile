# Use an official Python image
FROM python:3.12-slim

# Set the working directory in the container
WORKDIR /app

# Copy project files into the container
COPY . /app

# Install dependencies
RUN pip install --no-cache-dir fastapi uvicorn pyserial

# Expose the port FastAPI runs on
EXPOSE 8000

# Command to run FastAPI when the container starts
CMD ["uvicorn", "server:app", "--host", "0.0.0.0", "--port", "8000"]

