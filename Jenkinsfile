pipeline {
  agent{
    dockerfile {
      filename 'Dockerfile'
      dir 'build_env'
    }
  }

  stages {
    stage('SCM') {
      steps{
        checkout(
          [
            $class: 'GitSCM',
            branches: scm.branches,
            userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
          ]
        )
      }
    }

    stage('Build') {
      steps {
        sh "ls"
        sh "mkdir build"
        sh "cd build"
        sh "ls"
        sh "cmake ../src"
        sh "cmake --build ."
      }
    }    
  }
}
