FROM python:3.12-slim  // Use an official Python image


WORKDIR /app                                                            // Working directory

COPY . /app                                                             // Project files copy

RUN pip install --no-cache-dir fastapi uvicorn pyserial                 // Dependencies

EXPOSE 8000                                                             // Expose port

CMD ["uvicorn", "server:app", "--host", "0.0.0.0", "--port", "8000"]    // Command to run FastAPI when the container starts


